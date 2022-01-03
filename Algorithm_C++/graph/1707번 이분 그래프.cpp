#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int K, V, E;
vector<vector<int>> adj;
vector<int> visited;
bool chk;
void chkV(int idx);
void chkGraph();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> K;
	for (int testcase = 0; testcase < K; testcase++)
	{
		cin >> V >> E;
		chk = false;
		adj = vector<vector<int>>(V + 1, vector<int>());
		visited = vector<int>(V + 1, 0);
		for (int i = 0; i < E; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= V; i++)
		{
			if (visited[i] != 0) continue;
			chkV(i);
		}
		chkGraph();
		if (chk)cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}

	return 0;
}

void chkV(int idx)
{
	queue<pair<int, int>> q;
	q.push(make_pair(idx, 1));
	visited[idx] = 1;
	while (1)
	{
		if (q.empty())break;
		int here = q.front().first;
		int value = q.front().second;
		q.pop();
		if (value == 1)value = 2;
		else value = 1;
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i];
			if (visited[next] != 0)continue;
			visited[next] = value;
			q.push(make_pair(next, value));
		}


	}


}

void chkGraph()
{
	for (int i = 1; i <= V; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (visited[i] == visited[adj[i][j]])
			{
				chk = true;
				return;
			}
		}
	}
}
