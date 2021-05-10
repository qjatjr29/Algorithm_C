#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int M, N, H;
vector<vector<int>> tomato[101];
vector<vector<bool>> visited[101];
int tomatoCount = 0;
int notomatoCount = 0;
int _count;
int result;
queue<pair<pair<int, int>, pair<int, int>>> chk;
bool BFS(int x, int y, int z);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		tomato[i] = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
		visited[i] = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < M; z++)
			{
				int number;
				cin >> number;
				if (number == 1)
				{
					chk.push(make_pair(make_pair(j, z), make_pair(i, 0)));
					tomatoCount++;
				}
				else if (number == -1)notomatoCount++;
				tomato[i][j][z] = number;

			}
		}
	}
	if (M * N * H - notomatoCount == tomatoCount)
	{
		cout << 0 << "\n";
		return 0;
	}
	while (1)
	{
		if (chk.size() == 0)break;

		int size = chk.size();
		for (int i = 0; i < size; i++)
		{
			int curX = chk.front().first.first;
			int curY = chk.front().first.second;
			int curZ = chk.front().second.first;
			int curDay = chk.front().second.second;
			/*if (visited[curZ][curX][curY] == true)
			{
				chk.pop();
				continue;
			}*/
			if (result < curDay)result = curDay;
			chk.pop();
			if (BFS(curX - 1, curY, curZ))
			{
				chk.push(make_pair(make_pair(curX - 1, curY), make_pair(curZ, curDay + 1)));
			}
			if (BFS(curX + 1, curY, curZ))
			{
				chk.push(make_pair(make_pair(curX + 1, curY), make_pair(curZ, curDay + 1)));
			}
			if (BFS(curX, curY - 1, curZ))
			{
				chk.push(make_pair(make_pair(curX, curY - 1), make_pair(curZ, curDay + 1)));
			}
			if (BFS(curX, curY + 1, curZ))
			{
				chk.push(make_pair(make_pair(curX, curY + 1), make_pair(curZ, curDay + 1)));
			}
			if (BFS(curX, curY, curZ - 1))
			{
				chk.push(make_pair(make_pair(curX, curY), make_pair(curZ - 1, curDay + 1)));
			}
			if (BFS(curX, curY, curZ + 1))
			{
				chk.push(make_pair(make_pair(curX, curY), make_pair(curZ + 1, curDay + 1)));
			}
		}
	}

	if (M * N * H - notomatoCount == tomatoCount + _count)
	{
		cout << result << "\n";
	}
	else
	{
		cout << -1 << "\n";
	}

	return 0;
}

bool BFS(int x, int y, int z)
{
	if (x < 0 || y < 0 || z < 0 || x >= N || y >= M || z >= H)return false;
	if (visited[z][x][y] == true)return false;
	visited[z][x][y] = true;
	if (tomato[z][x][y] != 0)return false;

	_count++;
	return true;
}
