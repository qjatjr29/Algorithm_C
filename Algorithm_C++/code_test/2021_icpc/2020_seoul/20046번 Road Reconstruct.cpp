#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int m, n;
// 0 = 이미 도로 
// 1 = 비용이 1
// 2 = 비용이 2
// -1 = 도로를 지을 수 없다.
vector<vector<int>> map;
vector<vector<bool>> visited;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result = 987654321;
void reconstruction();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> m;

	map = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
	visited = vector<vector<bool>>(n + 1, vector < bool >(m + 1, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int state;
			cin >> state;
			map[i][j] = state;
		}
	}
	if (map[0][0] == -1 || map[n - 1][m - 1] == -1)
	{
		cout << -1 << "\n";
	}
	else
	{
		reconstruction();
		if (result == 987654321)
		{
			cout << -1 << "\n";
		}
		else
			cout << result << "\n";
	}



	return 0;
}

void reconstruction()
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(0, make_pair(0, 0)));
	while (1)
	{
		if (pq.empty())break;
		int cCost = -pq.top().first;
		int cX = pq.top().second.first;
		int cY = pq.top().second.second;
		visited[cX][cY] = true;
		pq.pop();

		if (cX == n - 1 && cY == m - 1)
		{
			result = cCost + map[0][0];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cX + dx[i];
			int ny = cY + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] != -1 && visited[nx][ny] == false)
			{
				pq.push(make_pair(-(cCost + map[nx][ny]), make_pair(nx, ny)));

			}
		}

	}
}
