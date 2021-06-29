#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int findNum;
int findX, findY;
vector<vector<int>> map;
vector<vector<bool>> visited;
// 0 이면 아래방향 1 - 오른쪽  2 - 위  3- 왼쪽
int dir;
int curX, curY;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> findNum;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
	int number = N * N;
	map[0][0] = number;
	number--;

	while (1)
	{
		if (number == 0)break;
		if (dir == 0)
		{
			if (curX + 1 >= 0 && curX + 1 < N && curY >= 0 && curY < N && map[curX + 1][curY] == -1)
			{
				map[curX + 1][curY] = number;
				if (number == findNum)
				{
					findX = curX + 1;
					findY = curY;
				}
				curX += 1;
				number--;
			}
			else
			{
				dir = 1;
			}
		}
		else if (dir == 1)
		{
			if (curX >= 0 && curX < N && curY + 1 >= 0 && curY + 1 < N && map[curX][curY + 1] == -1)
			{
				map[curX][curY + 1] = number;
				if (number == findNum)
				{
					findX = curX;
					findY = curY + 1;
				}
				curY += 1;
				number--;
			}
			else
			{
				dir = 2;
			}
		}
		else if (dir == 2)
		{
			if (curX - 1 >= 0 && curX - 1 < N && curY >= 0 && curY < N && map[curX - 1][curY] == -1)
			{
				map[curX - 1][curY] = number;
				if (number == findNum)
				{
					findX = curX - 1;
					findY = curY;
				}
				number--;
				curX--;
			}
			else
			{
				dir = 3;
			}
		}
		else if (dir == 3)
		{
			if (curX >= 0 && curX < N && curY - 1 >= 0 && curY - 1 < N && map[curX][curY - 1] == -1)
			{
				map[curX][curY - 1] = number;
				if (number == findNum)
				{
					findX = curX;
					findY = curY - 1;
				}
				number--;
				curY--;
			}
			else
			{
				dir = 0;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << map[i][N - 1] << "\n";
	}
	cout << findX + 1 << " " << findY + 1 << "\n";

	return 0;
}