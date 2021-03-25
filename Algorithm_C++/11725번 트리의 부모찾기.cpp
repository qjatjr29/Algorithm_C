#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<bool> _check;
vector<vector<int>> tree;
vector<vector<int>> result;
void parentnode(int nodenum);
int main()
{
	cin >> N;
	_check = vector<bool>(N + 1, false);
	tree = vector<vector<int>>(N + 1, vector<int>());
	result = vector<vector<int>>(N + 1, vector<int>());
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	parentnode(1);
	for (int i = 2; i <= N; i++)
	{
		cout << result[i][0] << "\n";
	}
	return 0;
}

void parentnode(int nodenum)
{
	if (_check[nodenum])return;
	_check[nodenum] = true;
	int _size = tree[nodenum].size();
	for (int i = 0; i < _size; i++)
	{
		int temp = tree[nodenum][i];
		result[temp].push_back(nodenum);
		parentnode(temp);
	}

}
