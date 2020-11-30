#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


struct Student
{
	string name;
	int age;
};

void input(string filename, vector<Student>& stu)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open())	return;

	while (!fi.eof())
	{
		string s;
		getline(fi, s);
		int pos = s.find(" - ");
		Student newbie;
		newbie.name = s.substr(0, pos);
		newbie.age = stoi(s.substr(pos + 3));
		stu.push_back(newbie);
	}
	fi.close();	
}

void printStu(vector<Student> stu)
{
	for (int i = 0; i < stu.size(); i++)
	{
		cout << stu[i].name << " - " << stu[i].age << endl;
	}
	cout << endl;
}

bool operator<(const Student& a, const Student& b)
{
	string name1, name2;
	int pos = a.name.rfind(" ");
	name1 = a.name.substr(pos + 1);
	pos = b.name.rfind(" ");
	name2 = b.name.substr(pos + 1);
	if (name1 == name2) return a.age < b.age;
	return name1 < name2;
}

bool operator>(const Student& a, const Student& b)
{
	return b < a;
}

void interchangeSortStu(vector<Student> &stu)
{
	int n = stu.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (stu[i] > stu[j]) swap(stu[i], stu[j]);
	}
}

void merge(vector<Student> &stu, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	Student* list1 = new Student[n1];
	Student* list2 = new Student[n2];

	int k = 0, l = 0;
	for (int i = left; i <= mid; i++)
		list1[k++] = stu[i];
	for (int j = mid + 1; j <= right; j++)
		list2[l++] = stu[j];
	k = 0, l = 0;
	for (int i = left; i <= right; i++)
	{
		if (k < n1 && (l >= n2 || list1[k] < list2[l]))
		{
			stu[i] = list1[k++];
		}
		else if (l < n2)
		{
			stu[i] = list2[l++];
		}
	}
	delete[] list1;
	delete[] list2;
}

void mergeSortStu(vector<Student>& stu, int left, int right)
{
	if (left >= right) return;
	int mid = left + (right - left) / 2;
		
	mergeSortStu(stu, left, mid);
	mergeSortStu(stu, mid + 1, right);
	merge(stu, left, mid, right);
}

void quickSortStu(vector<Student>& stu, int left, int right)
{
	int i = left, j = right;
	int mid = left + (right - left) / 2;

	while (i <= j)
	{
		while (stu[i] < stu[mid]) i++;
		while (stu[j] > stu[mid]) j--;

		if (i <= j)
		{
			swap(stu[i], stu[j]);
			i++; j--;
		}
	}
	if (left < j) quickSortStu(stu, left, j);
	if (right > i) quickSortStu(stu, i, right);
}

void heapify(vector<Student>& a, int parentIndex, int lastIndex)
{
	int left = parentIndex * 2 + 1;
	int right = parentIndex * 2 + 2;
	int biggest = parentIndex;

	if (left < lastIndex && a[left] > a[biggest])
		biggest = left;
	if (right < lastIndex && a[right] > a[biggest])
		biggest = right;
	if (biggest != parentIndex)
	{
		swap(a[biggest], a[parentIndex]);
		heapify(a, biggest, lastIndex);
	}
}

void heapSortStu(vector<Student>& stu, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(stu, i, n - 1);
	}
	for (int i = n - 1; i > 0; i--)
	{
		swap(stu[0], stu[i]);
		heapify(stu, 0, i);
	}
}

int main()
{
	vector<Student> stu;
	string filename = "data.txt";
	input(filename, stu);
	heapSortStu(stu, stu.size());
	printStu(stu);
	return 0;
}