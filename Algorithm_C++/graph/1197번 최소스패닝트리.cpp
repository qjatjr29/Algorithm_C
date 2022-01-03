#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> adj;
vector<vector<bool>> visited;
vector<int> parent;
int result;
int unionFind(int x);
void spanningTree();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> V >> E;
	adj = vector<pair<int, pair<int, int>>>();
	parent = vector<int>(V + 1, 0);
	for (int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}
	visited = vector<vector<bool>>(V + 1, vector<bool>(V + 1, false));
	for (int i = 0; i < E; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		adj.push_back(make_pair(cost, make_pair(start, end)));
		//adj.push_back(make_pair(cost, make_pair(end, start)));
		/*adj[start].push_back(make_pair(cost, end));
		adj[end].push_back(make_pair(cost, start));*/
	}

	sort(adj.begin(), adj.end());


	spanningTree();
	cout << result << "\n";
	return 0;
}

int unionFind(int x)
{
	if (x == parent[x])
	{
		return x;
	}
	else
	{
		int y = unionFind(parent[x]);
		parent[x] = y;
		return y;
	}
}

void spanningTree()
{

	for (int i = 0; i < E; i++)
	{
		int start = unionFind(adj[i].second.first);
		int end = unionFind(adj[i].second.second);
		if (start == end)continue;
		parent[start] = end;
		result += adj[i].first;
	}

}
