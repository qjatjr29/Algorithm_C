#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int V, E;
vector<vector<int>> adj;
int curCount;
vector<int> edgeCount;
priority_queue<pair<int, int>> result;
//int chk1, chk2;
int connectedComponent;
//int tempCount;
int connected(int idx, int root);
//void connected(int idx);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> V >> E;
	adj = vector<vector<int>>(V + 1, vector<int>());
	//visited = vector<bool>(V + 1, false);
	edgeCount = vector<int>(V + 1, 0);
	for (int i = 0; i < E; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
		//edge.push_back(make_pair(min(v1,v2), max(v1,v2)));
	}

	for (int i = 1; i <= V; i++)
	{
		if (edgeCount[i] == 0)
		{
			connected(i, 0);
		}
	}
	cout << result.size() << "\n";
	while (1)
	{
		if (result.empty())break;
		cout << -result.top().first << " " << -result.top().second << "\n";
		result.pop();

	}

	return 0;
}


int connected(int idx, int root)
{
	curCount++;
	edgeCount[idx] = curCount;
	int returnCount = edgeCount[idx];
	for (int i = 0; i < adj[idx].size(); i++)
	{

		int nextIndex = adj[idx][i];
		if (root == nextIndex)continue;
		if (edgeCount[nextIndex] != 0)
		{
			returnCount = min(returnCount, edgeCount[nextIndex]);
		}
		else
		{
			int preCount = connected(nextIndex, idx);
			if (preCount > edgeCount[idx])
			{
				result.push(make_pair(-min(idx, nextIndex), -max(idx, nextIndex)));
			}
			returnCount = min(returnCount, preCount);
		}
	}
	return returnCount;
}
