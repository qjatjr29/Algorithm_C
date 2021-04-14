#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int K;
int x, y;
vector<vector<int>> map;
int number = 1;
void sol(int curX, int curY, int condition, int size);
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> K;
	cin >> x >> y;
	int mapSize = pow(2, K);
	map = vector<vector<int>>(mapSize + 1, vector<int>(mapSize + 1, 0));
	// 배수구가 있는 위치
	map[mapSize - y + 1][x] = -1;

	if (mapSize > 2)
	{
		sol(1, 1, 0, mapSize);
		for (int i = 2; i < 4; i++)
		{
			for (int j = 2; j < 4; j++)
			{
				if (map[i][j] != -1 && map[i][j] == 0)
				{
					map[i][j] = number;
				}
			}
		}
	}
	else
	{
		sol(1, 1, 0, mapSize);
	}
	for (int i = 1; i <= mapSize; i++)
	{
		for (int j = 1; j <= mapSize; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}

void sol(int curX, int curY, int condition, int size)
{
	if (size == 2)
	{
		bool check = false;
		// 배수구 있는지 확인
		// 있다면 check true
		int targetX, targetY;
		for (int i = curX; i < curX + 2; i++)
		{
			if (check)break;
			for (int j = curY; j < curY + 2; j++)
			{
				if (map[i][j] == -1)
				{
					check = true;
					targetX = i;
					targetY = j;
					break;
				}
			}
		}
		// 배수구 없는 경우일 때
		if (!check)
		{
			// 왼쪽 위로 분할한 경우
			if (condition == 1)
			{
				targetX = curX + 1;
				targetY = curY + 1;
			}
			// 오른쪽 위로 분할한 경우
			else if (condition == 2)
			{
				targetX = curX + 1;
				targetY = curY;
			}
			// 왼쪽 아래로 분할한 경우
			else if (condition == 3)
			{
				targetX = curX;
				targetY = curY + 1;
			}
			// 오른쪽 아래로 분할한 경우
			else
			{
				targetX = curX;
				targetY = curY;
			}
		}

		for (int i = curX; i < curX + 2; i++)
		{
			for (int j = curY; j < curY + 2; j++)
			{
				if (targetX == i && targetY == j)
				{
					continue;
				}
				else
				{
					map[i][j] = number;
				}
			}
		}
		number++;
		return;
	}
	else
	{
		sol(curX, curY, 1, size / 2);
		sol(curX, curY + 2, 2, size / 2);
		sol(curX + 2, curY, 3, size / 2);
		sol(curX + 2, curY + 2, 4, size / 2);
	}
}
