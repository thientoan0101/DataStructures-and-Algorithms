#include <iostream> 
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
	int key;
	Node* next;
};

struct Stack
{
	Node* top;
	int count;
};

Node* createNode(int& data)
{
	Node* pNew = new Node;
	if (!pNew) return NULL;
	pNew->key = data;
	pNew->next = NULL;
	return pNew;
}

void initialize(Stack& st)
{
	st.top = NULL;
	st.count = 0;
}

bool isEmptyStack(Stack& st)
{
	return st.count == 0;
}

void push(Stack& st, int data)
{
	Node* p = createNode(data);
	if (p == NULL) return;

	if (isEmptyStack(st))
		st.top = p;
	else {
		p->next = st.top;
		st.top = p;
	}
	st.count++;
}

void pop(Stack& st, int& value)
{
	if (isEmptyStack(st))	return;

	value = st.top->key;
	Node* temp = st.top;
	st.top = st.top->next;
	delete temp;
	st.count--;
}

void top(Stack& st, int value)
{
	if (st.top == NULL) return;
	value = st.top->key;
}

void printStack(const Stack& st)
{
	Node* cur = st.top;
	while (cur)
	{
		cout << cur->key << endl;
		cur = cur->next;
	}
}

void destroyStack(Stack& st)
{
	while (st.top)
	{
		Node* temp = st.top;
		st.top = st.top->next;
		delete temp;
	}
	st.top = nullptr;
	st.count = 0;
}

void loadData(string filename, Stack& st)
{
	ifstream fi;
	fi.open(filename);
	if (!fi.is_open())	return;

	while (!fi.eof())
	{
		string s;
		fi >> s;
		push(st, stoi(s));
	}
	fi.close();
}

void selectionSort(Stack& st)
{
	Node* cur, * fast;
	cur = fast = st.top;

	for (cur = st.top;cur->next; cur = cur->next)
		for (fast = cur->next; fast; fast = fast->next)
		{
			if (cur->key > fast->key)
			{
				int temp = cur->key;
				cur->key = fast->key;
				fast->key = temp;
			}
		}
}






int main()
{
	Stack st;
	initialize(st);
	loadData("data.txt", st);
	printStack(st);
	cout << endl;
	selectionSort(st);
	printStack(st);
	destroyStack(st);
	return 0;
}