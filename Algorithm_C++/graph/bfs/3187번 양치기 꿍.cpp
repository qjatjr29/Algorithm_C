#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C;
int sheep, wolf;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<bool>> visited;
vector<vector<char>> map;
void findFence(int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> R >> C;
	map = vector<vector<char>>(R + 1, vector<char>(C + 1, ' '));
	visited = vector<vector<bool>>(R + 1, vector<bool>(C + 1, false));


	for (int i = 0; i < R; i++)
	{
		string state;
		cin >> state;
		for (int j = 0; j < state.size(); j++)
		{
			map[i][j] = state[j];
			if (state[j] == 'v')
			{
				wolf++;
			}
			else if (state[j] == 'k')
			{
				sheep++;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] != '#' && visited[i][j] == false)
			{
				findFence(i, j);
			}
		}
	}
	cout << sheep << " " << wolf << "\n";
	return 0;
}

void findFence(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	int wolfCount = 0;
	int sheepCount = 0;
	visited[x][y] = true;
	if (map[x][y] == 'v')
	{
		wolfCount++;
	}
	else if (map[x][y] == 'k')
	{
		sheepCount++;
	}
	while (1)
	{
		if (q.empty())break;

		int curX = q.front().first;
		int curY = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && visited[nextX][nextY] == false && map[nextX][nextY] != '#')
			{
				visited[nextX][nextY] = true;
				if (map[nextX][nextY] == 'k')
				{
					sheepCount++;
				}
				if (map[nextX][nextY] == 'v')
				{
					wolfCount++;
				}
				q.push(make_pair(nextX, nextY));
			}
		}
	}

	if (sheepCount > wolfCount)
	{
		wolf = wolf - wolfCount;
	}
	else
	{
		sheep = sheep - sheepCount;
	}



}
