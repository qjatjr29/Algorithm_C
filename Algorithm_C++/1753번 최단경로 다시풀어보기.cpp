#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int V, E;
vector<vector<pair<int, int>>> adj;
vector<int> result;
void minPath(int _start);
int main()
{
	cin >> V >> E;
	adj = vector<vector<pair<int, int>>>(V + 1);
	result = vector<int>(V + 1, 987654321);
	int startNum;
	cin >> startNum;
	for (int i = 1; i <= E; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		adj[start].push_back(make_pair(cost, end));
		//adj[end].push_back(make_pair(cost, start));
	}
	minPath(startNum);
	for (int i = 1; i <= V; i++)
	{

		if (result[i] == 987654321)
		{
			cout << "INF" << "\n";
		}
		else
		{
			cout << result[i] << "\n";
		}
	}

	return 0;
}

void minPath(int _start)
{
	result[_start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, _start));
	while (1)
	{
		if (pq.empty())break;
		int curCost = -pq.top().first;
		int index = pq.top().second;
		pq.pop();
		if (result[index] < curCost)continue;
		for (int i = 0; i < adj[index].size(); i++)
		{
			int nextIndex = adj[index][i].second;
			int nextCost = curCost + adj[index][i].first;
			if (result[nextIndex] > nextCost)
			{
				result[nextIndex] = nextCost;
				pq.push(make_pair(-nextCost, nextIndex));
			}

		}
	}
}
