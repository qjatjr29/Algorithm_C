#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MIN -987654321

int N, M;
int dx[3] = { 0,0,1 };
int dy[3] = { 1,-1,0 };
vector<vector<bool>> visited;
vector<vector<int>> location;
int dp[1001][1001][3];
int robot(int x, int y, int direction);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	visited = vector<vector<bool>>(N + 1, vector<bool>(M + 1, false));
	location = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int locationCost;
			cin >> locationCost;
			location[i][j] = locationCost;
			dp[i][j][0] = MIN;
			dp[i][j][1] = MIN;
			dp[i][j][2] = MIN;
		}
	}
	visited[0][0] = true;
	cout << robot(0, 0, 0) << "\n";


	return 0;
}

int robot(int x, int y, int direction)
{
	if (x == N - 1 && y == M - 1)return location[x][y];

	if (dp[x][y][direction] != MIN)return dp[x][y][direction];

	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny] == false)
		{
			visited[nx][ny] = true;
			dp[x][y][direction] = max(dp[x][y][direction], location[x][y] + robot(nx, ny, i));
			visited[nx][ny] = false;
		}
	}
	return dp[x][y][direction];


}
