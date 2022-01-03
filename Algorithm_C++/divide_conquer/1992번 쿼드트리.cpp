#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string compress(vector<string> tree, int x, int y, int size);

int main()
{

	int N;
	cin >> N;
	vector<string> tree;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		tree.push_back(s);
	}
	string result = compress(tree, 0, 0, N);
	cout << result << "\n";
	return 0;
}

string compress(vector<string> tree, int x, int y, int size)
{
	if (size == 1)
	{
		return string(1, tree[x][y]);
	}


	bool zerocheck = true;
	bool onecheck = true;

	// x 에서부터 size만큼 또 확인.
	// 똑같이 y에서 size만큼 확인
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (tree[i][j] == '0')
			{
				onecheck = false;
			}
			else zerocheck = false;
		}
	}
	if (onecheck)
	{
		return "1";
	}
	if (zerocheck)
	{
		return "0";
	}
	string Leftup = compress(tree, x, y, size / 2);
	string Rightup = compress(tree, x, y + (size / 2), size / 2);
	string Leftdown = compress(tree, x + (size / 2), y, size / 2);
	string Rightdown = compress(tree, x + (size / 2), y + (size / 2), size / 2);

	return ("(" + Leftup + Rightup + Leftdown + Rightdown) + ")";  // x일때 저 4개 다 돌고 나서 리턴.
}

