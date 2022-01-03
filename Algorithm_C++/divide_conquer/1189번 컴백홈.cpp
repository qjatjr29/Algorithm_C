#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


int R, C, K;
vector<vector<char>> map;
vector<vector<bool>> visited;
int result;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void findPath(int x, int y, int count);
int main()
{

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> R >> C >> K;
	map = vector<vector<char>>(R + 1, vector<char>(C + 1, ' '));
	visited = vector<vector<bool>>(R + 1, vector<bool>(C + 1, false));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char content;
			cin >> content;
			map[i][j] = content;
		}
	}
	findPath(R - 1, 0, 1);
	cout << result << "\n";
	return 0;
}

void findPath(int x, int y, int count)
{

	// 도착한 경우
	if (x == 0 && y == C - 1 && count == K)
	{
		result++;
	}

	else
	{

		visited[x][y] = true;
		/*int nextCount = count + 1;
		if (nextCount > K)return;*/
		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			// 범위 만족
			// 지나가지 않은 곳
			// T가 아닌 곳
			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && visited[nextX][nextY] == false && map[nextX][nextY] == '.')
			{
				findPath(nextX, nextY, count + 1);
			}
		}
		visited[x][y] = false;
	}


}
