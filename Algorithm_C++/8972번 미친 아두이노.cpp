#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int R, C;
int dx[9] = { 1,1,1,0,0,0,-1,-1,-1 };
int dy[9] = { -1,0,1,-1,0,1,-1,0,1 };
int cnt;
pair<int, int> mine;
vector<pair<int, int>> enemy;
vector<vector<char>> map;
bool gameover = true;
void moveEnemy();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> R >> C;
	map = vector<vector<char>>(R + 1, vector<char>(C + 1, ' '));

	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			char c = s[j];
			map[i][j] = c;
			if (c == 'I')
			{
				mine = make_pair(i, j);
			}
			if (c == 'R')
			{
				enemy.push_back(make_pair(i, j));
			}
		}
	}

	string command;
	cin >> command;
	for (int i = 0; i < command.size(); i++)
	{
		cnt++;
		// 종수 아두이노 이동
		int cmd = command[i] - '0';
		int curX = mine.first;
		int curY = mine.second;
		map[curX][curY] = '.';
		curX = curX + dx[cmd - 1];
		curY = curY + dy[cmd - 1];

		if (map[curX][curY] == 'R')
		{
			gameover = false;
			break;
		}
		else
		{
			mine = make_pair(curX, curY);
			map[curX][curY] = 'I';
		}

		moveEnemy();
		if (!gameover)break;
	}
	if (!gameover)
	{
		cout << "kraj " << cnt << "\n";
	}
	else
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}
	}


	return 0;
}

void moveEnemy()
{
	vector<pair<int, int>> temp;
	vector<vector<int>> temp_map;
	temp_map = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
	for (int i = 0; i < enemy.size(); i++)
	{
		int enemyX = enemy[i].first;
		int enemyY = enemy[i].second;
		map[enemyX][enemyY] = '.';
		int dist = 987654321;
		pair<int, int> m;
		for (int i = 0; i < 9; i++)
		{
			int nextX = enemyX + dx[i];
			int nextY = enemyY + dy[i];
			if (nextX == mine.first && nextY == mine.second)
			{
				gameover = false;
				break;
			}
			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C)
			{
				int distance = abs(nextX - mine.first) + abs(nextY - mine.second);
				if (distance < dist)
				{
					dist = distance;
					m = make_pair(nextX, nextY);
				}
			}
		}
		temp_map[m.first][m.second]++;
		if (!gameover)break;
	}
	if (!gameover)return;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (temp_map[i][j] == 1)
			{
				map[i][j] = 'R';
				temp.push_back(make_pair(i, j));
			}
		}
	}
	enemy = temp;


}

