#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> tree[10001];
int result;
int node;
vector<bool> visited;
void treeDiameter(int index, int diameter);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int parent, child, weight;
		cin >> parent >> child >> weight;
		tree[parent].push_back(make_pair(child, weight));
		tree[child].push_back(make_pair(parent, weight));
	}

	visited = vector<bool>(n + 1, false);

	treeDiameter(1, 0);
	result = 0;
	visited = vector<bool>(n + 1, false);
	treeDiameter(node, 0);
	cout << result << "\n";
	return 0;
}

void treeDiameter(int index, int diameter)
{
	visited[index] = true;
	if (diameter > result)
	{
		result = diameter;
		node = index;
	}
	for (int i = 0; i < tree[index].size(); i++)
	{
		int nextIndex = tree[index][i].first;
		if (visited[nextIndex] == false)
		{
			treeDiameter(nextIndex, diameter + tree[index][i].second);
		}
	}
}
