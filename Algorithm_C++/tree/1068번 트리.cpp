#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> tree;
int erase_parent;
int erasenodenumber;
int nodenumber;
void erasenode(int nodenum);
void getcount(int nodenum);
int main()
{
	cin >> N;
	tree = vector<vector<int>>(N, vector<int>());
	int rootnode;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		if (number == -1)
		{
			rootnode = i;
		}
		else
			tree[number].push_back(i);
	}
	cin >> erasenodenumber;
	erasenode(erasenodenumber);
	bool check = false;
	for (int i = 0; i < tree.size(); i++)
	{
		if (check)break;
		for (int j = 0; j < tree[i].size(); j++)
		{
			if (tree[i][j] == erasenodenumber)
			{
				check = true;
				tree[i].erase(tree[i].begin() + j, tree[i].begin() + j + 1);
				break;
			}
		}
	}
	getcount(rootnode);
	cout << nodenumber << "\n";

	return 0;
}

void erasenode(int nodenum)
{
	if (tree[nodenum].size() == 0)return;
	int size = tree[nodenum].size();

	for (int i = 0; i < size; i++)
	{
		erasenode(tree[nodenum][i]);
	}
	tree[nodenum].clear();
}

void getcount(int nodenum)
{
	if (tree[nodenum].size() == 0)
	{
		if (nodenum != erasenodenumber)
		{
			nodenumber++;
		}
		//nodenumber++;
		return;
	}
	int size = tree[nodenum].size();

	for (int i = 0; i < size; i++)
	{
		/*if (tree[nodenum][i] == erasenodenumber)
		{
			nodenumber++;
		}*/
		getcount(tree[nodenum][i]);
	}
}
