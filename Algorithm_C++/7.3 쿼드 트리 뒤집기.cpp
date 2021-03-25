#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<char> result;
string reverse(vector<char>::iterator& it);
string reverse(string tree, int count, int index);

int main()
{
	int c;
	cin >> c; // �׽�Ʈ���̽�

	for (int i = 0; i < c; i++)
	{
		string tree;
		vector<char> store;
		vector<char>::iterator iter;
		store.clear();
		cin >> tree;
		for (int j = 0; j < tree.size(); j++)
		{
			store.push_back(tree[j]);
		}
		int index = 0;
		iter = store.begin();

		string result;
		if (tree == "w" || tree == "b")
		{
			cout << tree << "\n";
		}
		else
		{
			result = reverse(iter);
			cout << result << "\n";
		}
	}

	return 0;
}

string reverse(vector<char>::iterator& it)
{
	string Leftup;
	string Rightup;
	string Leftdown;
	string Rightdown;

	//string result = "";

	char temp = *it;

	it++;
	if (temp == 'x')  // x �̸� �ѹ� �� ��. 
	{
		Leftup = reverse(it); // 1��° ���� �� 
		Rightup = reverse(it); //2
		Leftdown = reverse(it); // 3
		Rightdown = reverse(it);// 4   --> 3412 ��
		//index = index + 4;
	}
	else
	{
		return string(1, temp); // x�� �ƴҶ� b or w  �� ����.
	}


	return ("x" + Leftdown + Rightdown + Leftup + Rightup);  // x�϶� �� 4�� �� ���� ���� ����.
}

/*
string reverse(string tree, int count, int index)
{
	string Leftup;
	string Rightup;
	string Leftdown;
	string Rightdown;

	string temp = "";

	//index++;

	if (tree[index] == 'x')  // x �̸� �ѹ� �� ��.
	{
		Leftup = reverse(tree, count + 1, index+1); // 1��° ���� ��
		Rightup = reverse(tree, count + 1, index+2); //2
		Leftdown = reverse(tree, count + 1, index+3); // 3
		Rightdown = reverse(tree, count + 1, index+4);// 4   --> 3412 ��
		index = index + 4;
	}
	else
	{
		return temp += tree[index]; // x�� �ƴҶ� b or w  �� ����.
	}


	return (temp += "x" + Leftdown + Rightdown + Leftup + Rightup);  // x�϶� �� 4�� �� ���� ���� ����.











}
*/