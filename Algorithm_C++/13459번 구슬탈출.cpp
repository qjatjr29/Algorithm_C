#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;


int N, M;
vector<vector<char>> map;
pair<int, int> redB;
pair<int, int> blueB;
pair<int, int> goal;
bool visited[11][11][11][11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void moveBall();
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
				redB = make_pair(i, j);
			}
			else if (s[j] == 'B')
			{
				blueB = make_pair(i, j);
			}
			else if (s[j] == 'O')
			{
				goal = make_pair(i, j);
			}
		}
	}

	moveBall();

	return 0;
}

void moveBall()
{

	queue<pair<pair<int, int>, int>> redQ;
	queue<pair<pair<int, int>, int>> blueQ;

	redQ.push(make_pair(make_pair(redB.first, redB.second), 0));
	blueQ.push(make_pair(make_pair(blueB.first, blueB.second), 0));
	visited[redB.first][redB.second][blueB.first][blueB.second] = true;

	bool redChk = false;
	bool blueChk = false;


	while (1)
	{
		if (redQ.empty())break;

		int redX = redQ.front().first.first;
		int redY = redQ.front().first.second;
		int blueX = blueQ.front().first.first;
		int blueY = blueQ.front().first.second;

		int cnt = redQ.front().second;

		redQ.pop();
		blueQ.pop();
		if (cnt > 10)break;

		if (redX == goal.first && redY == goal.second)
		{
			redChk = true;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			blueChk = false;
			int nRedX = redX + dx[i];
			int nRedY = redY + dy[i];
			int nBlueX = blueX + dx[i];
			int nBlueY = blueY + dy[i];
			while (1)
			{

				if (map[nRedX][nRedY] == '#')
				{
					nRedX -= dx[i];
					nRedY -= dy[i];
					break;
				}
				if (map[nRedX][nRedY] == 'O')
				{
					break;
				}
				nRedX += dx[i];
				nRedY += dy[i];
			}
			while (1)
			{

				if (map[nBlueX][nBlueY] == '#')
				{
					nBlueX -= dx[i];
					nBlueY -= dy[i];
					break;
				}
				if (map[nBlueX][nBlueY] == 'O')
				{
					blueChk = true;
					break;
				}
				nBlueX += dx[i];
				nBlueY += dy[i];
			}

			// 안되는 경우.
			if (blueChk)
			{
				continue;
			}


			// 같은 자리
			if (nRedX == nBlueX && nRedY == nBlueY)
			{
				switch (i)
				{
				case 0:
					if (redX < blueX)
					{
						nBlueX++;
					}
					else
					{
						nRedX++;
					}
					break;
				case 1:
					if (redX < blueX)
					{
						nRedX--;

					}
					else
					{
						nBlueX--;
					}
					break;
				case 2:
					if (redY < blueY)
					{
						nBlueY++;
					}
					else
					{
						nRedY++;
					}
					break;
				case 3:
					if (redY < blueY)
					{
						nRedY--;
					}
					else
					{
						nBlueY--;
					}
					break;
				default:
					break;
				}
			}

			if (visited[nRedX][nRedY][nBlueX][nBlueY])continue;
			else visited[nRedX][nRedY][nBlueX][nBlueY] = true;

			redQ.push(make_pair(make_pair(nRedX, nRedY), cnt + 1));
			blueQ.push(make_pair(make_pair(nBlueX, nBlueY), cnt + 1));

		}

	}

	if (redChk)
	{
		cout << 1 << "\n";
	}
	else cout << 0 << "\n";


}
