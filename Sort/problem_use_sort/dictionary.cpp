#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct WORD
{
	string word;
	string definition;
};



void loadData(string filename, vector<WORD>& dict)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open())	return;

	while (!fi.eof())
	{
		string s;
		WORD w;
		getline(fi, s);
		int pos = s.find(":");
		w.word = s.substr(0, pos);
		w.definition = s.substr(pos + 1);
		dict.push_back(w);
	}
	fi.close();
}

void sortDict(vector<WORD>& dict, int left, int right)
{
	int i = left, j = right;
	int mid = left + (right - left) / 2;
	while (i <= j)
	{
		while (dict[i].word < dict[mid].word) i++;
		while (dict[j].word > dict[mid].word) j--;

		if (i <= j)
		{
			swap(dict[i], dict[j]);
			i++; j--;
		}
	}
	if (left < j) sortDict(dict, left, j);
	if (i < right) sortDict(dict, i, right);
}

void printDict(vector<WORD> dict, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << dict[i].word << ": " << dict[i].definition << endl;
	}
	cout << endl;
}


int main()
{
	vector<WORD> dictionary;
	string nameFile = "data.txt";
	loadData(nameFile, dictionary);
	printDict(dictionary, dictionary.size());
	sortDict(dictionary, 0, dictionary.size() - 1);
	printDict(dictionary, dictionary.size());

	return 0;
}