#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<char>> map;
pair<int, int> Red;
pair<int, int> Blue;
pair<int, int> hole;
bool check = false;
int result = 987654321;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int visited[11][11][11][11];
void move();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	map = vector<vector<char>>(N + 1, vector<char>(M + 1, ' '));
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			map[i][j] = s[j];
			if (s[j] == 'R')
			{
				Red = make_pair(i, j);
			}
			if (s[j] == 'B')
			{
				Blue = make_pair(i, j);
			}
			if (s[j] == 'O')
			{
				hole = make_pair(i, j);
			}
		}
	}
	visited[Red.first][Red.second][Blue.first][Blue.second] = 1;
	move();
	if (result == 987654321)
		cout << -1 << "\n";
	else cout << result << "\n";
	return 0;
}

void move()
{
	queue<pair<pair<int, int>, int>> redball;
	queue<pair<pair<int, int>, int>> blueball;
	redball.push(make_pair(make_pair(Red.first, Red.second), 0));
	blueball.push(make_pair(make_pair(Blue.first, Blue.second), 0));

	// 파란공이 구멍에 들어간 경우 체크
	bool Bluecheck = false;
	// 빨간공이 구멍에 들어 갓는지 체크
	bool RedCheck = false;
	while (1)
	{
		//if (Bluecheck == true)break;
		if (redball.empty())break;

		int redX = redball.front().first.first;
		int redY = redball.front().first.second;
		int count = redball.front().second;

		int blueX = blueball.front().first.first;
		int blueY = blueball.front().first.second;

		redball.pop();
		blueball.pop();
		if (count > 10)break;
		if (redX == hole.first && redY == hole.second)
		{
			RedCheck = true;
			result = count;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			// 위로 기울리는 경우 i==0
			// 아래로 기울리는 경우 i==1
			// 왼쪽으로 기울리는 경우 i==2
			// 오른쪽으로 기울리는 경우 i==3
			int Rx = redX + dx[i];
			int Ry = redY + dy[i];
			int Bx = blueX + dx[i];
			int By = blueY + dy[i];
			Bluecheck = false;

			// 테두리는 항상 #으로 감싸져 있음.

			// 빨간색 공 움직임
			while (1)
			{
				if (map[Rx][Ry] == '#')
				{
					Rx -= dx[i];
					Ry -= dy[i];
					break;
				}
				if (map[Rx][Ry] == 'O')
				{
					break;
				}
				Rx += dx[i];
				Ry += dy[i];
			}
			// 파란색 공 움직임
			while (1)
			{
				if (map[Bx][By] == '#')
				{
					Bx -= dx[i];
					By -= dy[i];
					break;
				}
				if (map[Bx][By] == 'O')
				{
					Bluecheck = true;
					break;
				}
				Bx += dx[i];
				By += dy[i];
			}
			// 파란색공이 빠진 경우
			// 이번 케이스는 그냥 넘어간다.
			if (Bluecheck)
			{
				continue;
			}
			// 같은 곳에 있는 경우
			if (Rx == Bx && Ry == By)
			{
				if (i == 0)
				{
					if (redX > blueX)
					{
						Rx++;
					}
					else Bx++;
				}
				else if (i == 1)
				{
					if (redX < blueX)
					{
						Rx--;
					}
					else Bx--;
				}
				else if (i == 2)
				{
					if (redY > blueY)
					{
						Ry++;
					}
					else By++;
				}
				else if (i == 3)
				{
					if (redY < blueY)
					{
						Ry--;
					}
					else By--;
				}
			}
			// 이미 방문했던 경우면 넘어가기
			if (visited[Rx][Ry][Bx][By] == 1)continue;

			redball.push(make_pair(make_pair(Rx, Ry), count + 1));
			blueball.push(make_pair(make_pair(Bx, By), count + 1));
			visited[Rx][Ry][Bx][By] = 1;


		}
	}
}
