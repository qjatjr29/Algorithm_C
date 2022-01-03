#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int dx[4] = { -1,1,0,0, };
int dy[4] = { 0,0,-1,1 };
vector<vector<int>> cheeseMap;
// 내부 공기인지 확인하기 위한 벡터.
// default ==> 0 , 치즈가 있는 공간 ==> 1 , 외부 공기 ==> -1 
// BFS 탐색을 통해 외부 / 내부 공기 나눈다 --> 내부는 0으로 남아 있을 것.
vector<vector<int>> Air;
vector<vector<bool>> visited;
void BFSAir();
vector<pair<int, int>> removeCheese;
int cheeseCount;
int meltTime;
void meltCheese();
void AddAir();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;

	cheeseMap = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	Air = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int cheeseState;
			cin >> cheeseState;
			cheeseMap[i][j] = cheeseState;
			if (cheeseState == 1)
			{
				cheeseCount++;
				Air[i][j] = 1;
			}
		}
	}
	BFSAir();
	while (1)
	{
		if (cheeseCount == 0)break;
		meltCheese();
		AddAir();
	}
	cout << meltTime << "\n";
	return 0;
}

void BFSAir()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	Air[0][0] = -1;
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
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M)
			{
				// 치즈가 아니고 한번도 방문하지 않은 곳
				if (Air[nextX][nextY] == 0)
				{
					// 외부 공기 
					Air[nextX][nextY] = -1;
					q.push(make_pair(nextX, nextY));
				}
			}
		}
	}
}

void meltCheese()
{
	//removeCheese = vector<pair<int, int>>();
	removeCheese.clear();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cheeseMap[i][j] == 1)
			{
				int emptyCount = 0;
				for (int z = 0; z < 4; z++)
				{
					if (emptyCount >= 2)break;
					int checkX = i + dx[z];
					int checkY = j + dy[z];

					if (checkX >= 0 && checkX < N && checkY >= 0 && checkY < M && Air[checkX][checkY] == -1)
					{
						if (cheeseMap[checkX][checkY] == 0)emptyCount++;
					}
				}
				if (emptyCount >= 2)
				{
					removeCheese.push_back(make_pair(i, j));
				}
			}
		}
	}
	for (int i = 0; i < removeCheese.size(); i++)
	{
		cheeseMap[removeCheese[i].first][removeCheese[i].second] = 0;
		cheeseCount--;
	}

	meltTime++;
}

void AddAir()
{
	while (1)
	{
		if (removeCheese.empty())break;
		int startX = removeCheese[0].first;
		int startY = removeCheese[0].second;
		removeCheese.erase(removeCheese.begin(), removeCheese.begin() + 1);
		Air[startX][startY] = -1;
		for (int i = 0; i < 4; i++)
		{
			int sx = startX + dx[i];
			int sy = startY + dy[i];
			if (Air[sx][sy] == 0)
			{
				Air[sx][sy] = -1;
				removeCheese.push_back(make_pair(sx, sy));
			}
		}
	}
}
