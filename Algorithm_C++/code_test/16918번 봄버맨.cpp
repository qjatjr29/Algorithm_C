#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R, C, N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<int>> bombMap;
vector<string> resultMap;
void setBomb();
void OneSecLater();
void ExplosionBomb();
int bombTime = 1;
int resultTime = 1;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> R >> C >> N;
	// 0ÀÌ¸é ºóÄ­ 1ÀÌ¸é ÆøÅº
	bombMap = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
	for (int i = 0; i < R; i++)
	{
		string bombStates;
		cin >> bombStates;
		for (int j = 0; j < bombStates.size(); j++)
		{
			char bombState = bombStates[j];
			if (bombState == 'O')
			{
				bombMap[i][j] = 2;
			}
		}
	}
	while (1)
	{
		if (resultTime == N)break;
		setBomb();
		if (resultTime == N)break;
		OneSecLater();
		ExplosionBomb();
		if (resultTime == N)break;

	}
	for (int i = 0; i < R; i++)
	{
		string temp = "";
		for (int j = 0; j < C; j++)
		{
			if (bombMap[i][j] == 0)
			{
				temp += '.';
			}
			else
			{
				temp += 'O';
			}
		}
		cout << temp << "\n";
	}
	return 0;
}

void setBomb()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (bombMap[i][j] == 0)
			{
				bombMap[i][j] = 1;
			}
		}
	}
	resultTime++;
}

void OneSecLater()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			bombMap[i][j]++;
		}
	}
	resultTime++;
}

void ExplosionBomb()
{
	vector<pair<int, int>> v;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (bombMap[i][j] == 3)
			{
				v.push_back(make_pair(i, j));
				for (int z = 0; z < 4; z++)
				{
					int nextX = i + dx[z];
					int nextY = j + dy[z];
					if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C)
					{
						if (bombMap[nextX][nextY] == 3)continue;
						bombMap[nextX][nextY] = 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		int bombX = v[i].first;
		int bombY = v[i].second;
		bombMap[bombX][bombY] = 0;
	}
	//resultTime++;
}
