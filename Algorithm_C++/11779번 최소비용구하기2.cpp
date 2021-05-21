#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int a, b;
vector<vector<pair<int, int>>> adj;
vector<vector<bool>> visited;
int result = 987654321;
vector<int> nodeCost;
vector<int> route;
int temp[1001];
void city(int start);
int main()
{
	cin >> n >> m;
	adj = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
	visited = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
	nodeCost = vector<int>(n + 1, 987654321);
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start].push_back(make_pair(end, cost));
	}
	cin >> a >> b;
	city(a);
	cout << nodeCost[b] << "\n";
	int curIndex = b;
	while (1)
	{
		if (curIndex == a)
		{
			route.push_back(a);
			break;
		}
		route.push_back(curIndex);
		curIndex = temp[curIndex];
	}
	int size = route.size();
	cout << size << "\n";
	for (int i = size - 1; i > 0; i--)
	{
		cout << route[i] << " ";
	}
	cout << route[0] << "\n";


	return 0;
}

void city(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));

	while (1)
	{
		if (pq.empty())break;
		int curCost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();


		for (int i = 0; i < adj[here].size(); i++)
		{
			int there = adj[here][i].first;
			int nextCost = curCost + adj[here][i].second;
			if (nodeCost[there] > nextCost)
			{
				nodeCost[there] = nextCost;
				temp[there] = here;
				pq.push(make_pair(-nextCost, there));
			}
		}

	}
}
