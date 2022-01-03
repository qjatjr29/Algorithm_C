#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int a, b;
int N, M;
vector<vector<int>> adj;
vector<vector<bool>> visited;
int result = 987654321;
void change(int start);
int main()
{
	cin >> a >> b;
	cin >> N >> M;
	adj = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < M; i++)
	{
		int tempA, tempB;
		cin >> tempA >> tempB;
		adj[tempA].push_back(tempB);
		adj[tempB].push_back(tempA);
	}
	if (a == b)
	{
		cout << 0 << "\n";
	}
	else
	{
		change(a);
		if (result == 987654321)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << result << "\n";
		}
	}

	return 0;
}

void change(int start)
{
	priority_queue<pair<int, int>> pq;
	queue<pair<int, int>> q;
	pq.push(make_pair(0, start));
	while (1)
	{
		if (pq.empty())break;

		int curCost = -pq.top().first;
		int curIndex = pq.top().second;
		pq.pop();
		for (int i = 0; i < adj[curIndex].size(); i++)
		{
			int nextIndex = adj[curIndex][i];
			if (visited[nextIndex][i] == true)continue;
			if (nextIndex == b)
			{
				result = min(result, curCost + 1);
			}
			else
			{
				visited[nextIndex][i] = true;
				visited[i][nextIndex] = true;
				pq.push(make_pair(-(curCost + 1), nextIndex));
			}

		}
	}
}
