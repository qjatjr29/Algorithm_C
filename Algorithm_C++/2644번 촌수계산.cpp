#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int start, _end;
vector<vector<int>> adj;
vector<bool> visited;
int result = 987654321;

void family(int start);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;
	cin >> start >> _end;
	cin >> m;
	adj = vector<vector<int>>(n + 1, vector<int>());
	visited = vector<bool>(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int person1, person2;
		cin >> person1 >> person2;
		adj[person1].push_back(person2);
		adj[person2].push_back(person1);
	}
	family(start);
	if (result == 987654321)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << result << "\n";
	}

	return 0;
}

void family(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, start));
	visited[start] = true;
	while (1)
	{
		if (pq.empty())break;
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (here == _end)
		{
			result = min(result, cost);
			continue;
		}

		for (int i = 0; i < adj[here].size(); i++)
		{
			int nextCost = cost + 1;
			int there = adj[here][i];
			if (visited[there] == false)
			{
				pq.push(make_pair(-nextCost, there));
				visited[there] = true;
			}
		}


	}

}
