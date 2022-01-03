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
	cin >> c; // 테스트케이스

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
	if (temp == 'x')  // x 이면 한번 더 들어감. 
	{
		Leftup = reverse(it); // 1번째 왼쪽 위 
		Rightup = reverse(it); //2
		Leftdown = reverse(it); // 3
		Rightdown = reverse(it);// 4   --> 3412 순
		//index = index + 4;
	}
	else
	{
		return string(1, temp); // x가 아닐때 b or w  를 더함.
	}


	return ("x" + Leftdown + Rightdown + Leftup + Rightup);  // x일때 저 4개 다 돌고 나서 리턴.
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

	if (tree[index] == 'x')  // x 이면 한번 더 들어감.
	{
		Leftup = reverse(tree, count + 1, index+1); // 1번째 왼쪽 위
		Rightup = reverse(tree, count + 1, index+2); //2
		Leftdown = reverse(tree, count + 1, index+3); // 3
		Rightdown = reverse(tree, count + 1, index+4);// 4   --> 3412 순
		index = index + 4;
	}
	else
	{
		return temp += tree[index]; // x가 아닐때 b or w  를 더함.
	}


	return (temp += "x" + Leftdown + Rightdown + Leftup + Rightup);  // x일때 저 4개 다 돌고 나서 리턴.











}
*/