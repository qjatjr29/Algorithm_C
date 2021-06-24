#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> ice;
int _minus[301][301];
vector<vector<bool>> visited;
int year;
bool check;
bool zeroCase;
void sol();
void dfs(int x, int y);
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int findZero(int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	ice = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	check = true;
	zeroCase = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int number;
			cin >> number;
			ice[i][j] = number;
		}
	}
	visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
	while (1)
	{
		sol();
		if (!check)break;
		if (zeroCase)break;
		visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				if (ice[i][j] > 0)
				{
					_minus[i][j] = findZero(i, j);
				}
			}
		}
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				ice[i][j] -= _minus[i][j];
			}
		}
		year++;
	}
	if (zeroCase)cout << 0 << "\n";
	else
	{
		cout << year << "\n";
	}
	return 0;
}
void sol()
{
	int count = 0;
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			if (visited[i][j] == false && ice[i][j] > 0)
			{
				count++;
				dfs(i, j);
			}
		}
	}
	if (count > 1)
	{
		check = false;
	}
	if (count == 0) zeroCase = true;
}
void dfs(int x, int y)
{
	visited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x < 0 || _x >= N || _y < 0 || _y >= M)continue;
		else
		{
			if (visited[_x][_y] == false && ice[_x][_y] > 0)
			{
				dfs(_x, _y);
			}
		}
	}
}
int findZero(int x, int y)
{
	int returnNum = 0;
	for (int i = 0; i < 4; i++)
	{
		int _x = x + dx[i];
		int _y = y + dy[i];
		if (_x < 0 || _x >= N || _y < 0 || _y >= M)continue;
		if (ice[_x][_y] <= 0)returnNum++;
	}
	return returnNum;
}
