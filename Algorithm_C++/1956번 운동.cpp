#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<vector<bool>> visited;
int result = 987654321;
void findCycle(int startIndex);
int dp[401][401];
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> V >> E;
	adj = vector<vector<int>>(V + 1, vector<int>(V + 1, 987654321));
	for (int i = 0; i < E; i++)
	{
		int startCity, endCity, cost;
		cin >> startCity >> endCity >> cost;
		adj[startCity][endCity] = cost;
	}

	// 플로이드 마샬 알고리즘
	// x-->y로 가능 최소 비용  vs   x --> z --> y 로 가능 최소 비용
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int z = 1; z <= V; z++)
			{
				if (adj[j][i] + adj[i][z] < adj[j][z])
				{
					adj[j][z] = adj[j][i] + adj[i][z];
				}
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (adj[i][i] != 987654321)
		{
			result = min(result, adj[i][i]);
		}
	}

	if (result == 987654321)
	{
		cout << -1 << "\n";
	}
	else cout << result << "\n";
	return 0;
}

// 시간 초과

void findCycle(int startIndex)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, startIndex));
	visited = vector<vector<bool>>(V + 1, vector<bool>(V + 1, false));

	while (1)
	{
		if (pq.empty())break;

		int loadLength = -pq.top().first;
		int curIndex = pq.top().second;
		pq.pop();
		for (int i = 1; i < V + 1; i++)
		{
			int plusLength = adj[curIndex][i];

			if (plusLength != -1 && visited[curIndex][i] == false)
			{

				if (i == startIndex)
				{
					result = min(result, loadLength + plusLength);
				}
				else
				{
					visited[curIndex][i] = true;
					int nextLength = loadLength + plusLength;
					pq.push(make_pair(-nextLength, i));
				}
			}
		}


	}
}
