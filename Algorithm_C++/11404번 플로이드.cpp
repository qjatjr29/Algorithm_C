#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> result;
vector<bool> visited;
void calCost(int start, int end);
void floyd();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 987654321));
	result = vector<vector<int>>(n + 1, vector<int>(n + 1, 987654321));
	visited = vector<bool>(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int city1, city2, cost;
		cin >> city1 >> city2 >> cost;
		if (adj[city1][city2] != 0)
		{
			adj[city1][city2] = min(adj[city1][city2], cost);
		}
		else adj[city1][city2] = cost;
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)continue;
			calCost(i, j);

		}
	}*/
	floyd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			if (adj[i][j] == 987654321)
			{
				cout << 0 << " ";
			}
			else
			{
				cout << adj[i][j] << " ";
			}

		}
		if (adj[i][n] == 987654321)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << adj[i][n] << "\n";
		}

	}

	return 0;
}

void calCost(int start, int end)
{
	visited = vector<bool>(n + 1, false);
	visited[start] = true;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	while (1)
	{
		if (pq.empty())break;
		int curCost = -pq.top().first;
		int curIndex = pq.top().second;
		visited[curIndex] = true;
		pq.pop();

		for (int i = 1; i <= n; i++)
		{
			if (i == curIndex)continue;
			// 도착한 경우
			if (adj[curIndex][i] > 0 && i == end)
			{
				int _cost = curCost + adj[curIndex][i];
				if (result[start][i] > _cost)
				{
					result[start][i] = _cost;
				}
			}
			// 도착 x 다른 도시로 이동
			else if (adj[curIndex][i] > 0 && visited[i] == false)
			{

				int _cost = curCost + adj[curIndex][i];
				pq.push(make_pair(-_cost, i));
			}
		}

	}
}

void floyd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int z = 1; z <= n; z++)
			{
				if (j == z)continue;
				if (adj[j][i] != 987654321 && adj[i][z] != 987654321)
				{
					adj[j][z] = min(adj[j][z], adj[j][i] + adj[i][z]);
				}
			}
		}
	}
}
