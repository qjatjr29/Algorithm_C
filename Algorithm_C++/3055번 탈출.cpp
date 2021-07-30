#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int R, C;
vector<vector<char>> map;
queue<pair<int, int>> water;
queue<pair<int, int>> hedgehog;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int moveSec;
bool endCheck = false;
bool checkHedgehog();
void moveHedgehog();
int main()
{

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> R >> C;
	map = vector<vector<char>>(R + 1, vector<char>(C + 1, 0));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char mapState;
			cin >> mapState;
			map[i][j] = mapState;

			if (mapState == 'S')
			{
				hedgehog.push(make_pair(i, j));
			}
			else if (mapState == '*')
			{
				water.push(make_pair(i, j));
			}
		}
	}
	moveHedgehog();

	if (endCheck)
	{
		cout << moveSec << "\n";
	}
	else
	{
		cout << "KAKTUS" << "\n";
	}
	return 0;
}

bool checkHedgehog()
{
	int size = hedgehog.size();

	for (int i = 0; i < size; i++)
	{
		int _x = hedgehog.front().first;
		int _y = hedgehog.front().second;
		//map[_x][_y] = '.';
		hedgehog.pop();
		//hedgehog.erase(hedgehog.begin()+i,hedgehog.begin()+i+1);
		for (int j = 0; j < 4; j++)
		{
			int move_X = _x + dx[j];
			int move_Y = _y + dy[j];
			if (move_X >= 0 && move_X < R && move_Y >= 0 && move_Y < C)
			{
				if (map[move_X][move_Y] == '.')
				{
					map[move_X][move_Y] = 'S';
					hedgehog.push(make_pair(move_X, move_Y));
				}
				if (map[move_X][move_Y] == 'D')
				{
					hedgehog.push(make_pair(move_X, move_Y));
					return true;
				}
			}
		}
	}


	return false;
}

void moveHedgehog()
{

	while (1)
	{
		moveSec++;
		if (hedgehog.empty())break;


		// 물 먼저 이동
		int waterSize = water.size();

		for (int i = 0; i < waterSize; i++)
		{
			int waterX = water.front().first;
			int waterY = water.front().second;
			water.pop();
			for (int j = 0; j < 4; j++)
			{
				int nextX = waterX + dx[j];
				int nextY = waterY + dy[j];
				if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && map[nextX][nextY] == '.')
				{
					water.push(make_pair(nextX, nextY));
					map[nextX][nextY] = '*';
				}
			}
		}

		// 고슴도치 이동

		if (checkHedgehog() == true)
		{
			endCheck = true;
			break;
		}

	}


}
