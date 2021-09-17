#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K, R;
int mx[4] = { -1,1,0,0 };
int my[4] = { 0,0,-1,1 };
bool path[101][101][101][101];
vector<vector<bool>> visited;
vector<pair<int, int>> cow;
int result;
void moveCow(int sx, int sy, int dx, int dy);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K >> R;

	for (int i = 0; i < R; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		path[sx][sy][ex][ey] = true;
		path[ex][ey][sx][sy] = true;
	}
	for (int i = 0; i < K; i++)
	{
		int cx, cy;
		cin >> cx >> cy;
		cow.push_back(make_pair(cx, cy));
	}
	result = (cow.size() * (cow.size() - 1)) / 2;
	for (int i = 0; i < cow.size(); i++)
	{
		int startx = cow[i].first;
		int starty = cow[i].second;
		for (int j = i + 1; j < cow.size(); j++)
		{
			int endx = cow[j].first;
			int endy = cow[j].second;
			moveCow(startx, starty, endx, endy);
		}
	}
	cout << result << "\n";
	return 0;
}

void moveCow(int sx, int sy, int dx, int dy)
{
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	visited[sx][sy] = true;

	while (1)
	{
		if (q.empty())break;
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		if (curX == dx && curY == dy)
		{
			result--;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + mx[i];
			int ny = curY + my[i];
			bool chk = false;
			if (nx > 0 && nx <= N && ny > 0 && ny <= N)
			{
			
				if (path[curX][curY][nx][ny] == true)
				{
					chk = true;
				}
				if (chk)continue;
				// 길을 건너지 않고 도착한 경우
				if (nx == dx && ny == dy)
				{
					result--;
					return;
				}
				if (visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}