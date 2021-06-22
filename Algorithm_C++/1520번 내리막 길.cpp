#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<int>> visited;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void path(int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> M >> N;
	map = vector<vector<int>>(M, vector<int>(N, 0));
	visited = vector<vector<int>>(M, vector<int>(N, 0));
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			map[i][j] = number;
		}
	}
	path(0, 0);
	if (M == 1 && N == 1)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << visited[M - 1][N - 1] << "\n";
	}

	return 0;
}

void path(int x, int y)
{
	priority_queue<pair<int, pair<int, int>>> pq;
	visited[x][y] = 1;
	if (y + 1 < N && map[x][y + 1] < map[x][y])
	{
		pq.push(make_pair(map[x][y + 1], make_pair(x, y + 1)));
		visited[x][y + 1]++;
	}
	if (x + 1 < M && map[x + 1][y] < map[x][y])
	{
		pq.push(make_pair(map[x + 1][y], make_pair(x + 1, y)));
		visited[x + 1][y]++;
	}

	while (1)
	{
		if (pq.empty())break;

		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		int curCost = pq.top().first;
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int _x = curX + dx[i];
			int _y = curY + dy[i];
			if (_x >= 0 && _y >= 0 && _x < M && _y < N && map[_x][_y] < curCost)
			{
				if (visited[_x][_y] == 0)
				{
					pq.push(make_pair(map[_x][_y], make_pair(_x, _y)));
				}
				visited[_x][_y] += visited[curX][curY];
			}
		}

	}
}
