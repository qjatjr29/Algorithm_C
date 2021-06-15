#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int N;
vector<vector<char>> rgb;
vector<vector<bool>> visited;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result;
int result2;
void FindSection(int x, int y);
void FindSection2(int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	rgb = vector<vector<char>>(N + 1, vector<char>(N + 1, ' '));
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < N; i++)
	{
		string color;
		cin >> color;
		for (int j = 0; j < color.size(); j++)
		{
			rgb[i][j] = color[j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
			{
				visited[i][j] = true;
				FindSection(i, j);
				result++;
			}
		}
	}
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == false)
			{
				visited[i][j] = true;
				FindSection2(i, j);
				result2++;
			}
		}
	}
	cout << result << " " << result2 << "\n";

	return 0;
}

// 적록색약이 아닌 사람.
void FindSection(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N) return;

	char curColor = rgb[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
		{
			if (rgb[nextX][nextY] == curColor && visited[nextX][nextY] == false)
			{
				visited[nextX][nextY] = true;
				FindSection(nextX, nextY);
			}
		}
	}
}

void FindSection2(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N) return;

	char curColor = rgb[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N)
		{
			if (curColor == 'R' || curColor == 'G')
			{
				if ((rgb[nextX][nextY] == 'R' || rgb[nextX][nextY] == 'G') && visited[nextX][nextY] == false)
				{
					visited[nextX][nextY] = true;
					FindSection2(nextX, nextY);
				}
			}
			if (rgb[nextX][nextY] == curColor && visited[nextX][nextY] == false)
			{
				visited[nextX][nextY] = true;
				FindSection2(nextX, nextY);
			}
		}
	}
}

