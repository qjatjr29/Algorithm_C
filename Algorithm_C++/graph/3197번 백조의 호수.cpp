#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int R, C;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result;
bool swanCheck = false;
vector<vector<bool>> visited;
vector<vector<char>> lake;
queue<pair<int, int>> water;
vector<pair<int, int>> swan;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> R >> C;

	lake = vector<vector<char>>(R + 1, vector<char>(C + 1, ' '));
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			char state = s[j];
			lake[i][j] = state;
			if (state == 'L')
			{
				swan.push_back(make_pair(i, j));
			}
			if (state == 'L' || state == '.')
			{
				water.push(make_pair(i, j));
			}
		}
	}
	queue<pair<int, int>> q;
	q.push(swan[0]);

	visited = vector<vector<bool>>(R + 1, vector<bool>(C + 1, false));
	visited[swan[0].first][swan[0].second] = true;

	while (1)
	{
		queue<pair<int, int>> nextCase;
		while (1)
		{
			if (q.empty())break;
			int curX = q.front().first;
			int curY = q.front().second;
			q.pop();

			// µµÂø
			if (curX == swan[1].first && curY == swan[1].second)
			{
				swanCheck = true;
				break;
			}


			for (int i = 0; i < 4; i++)
			{
				int nextX = curX + dx[i];
				int nextY = curY + dy[i];
				if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && visited[nextX][nextY] == false)
				{
					visited[nextX][nextY] = true;
					if (lake[nextX][nextY] == 'X')
					{
						nextCase.push(make_pair(nextX, nextY));
						continue;
					}
					q.push(make_pair(nextX, nextY));
				}
			}

		}
		if (swanCheck)break;
		q = nextCase;

		int waterSize = water.size();
		while (1)
		{
			if (waterSize == 0)break;
			int wx = water.front().first;
			int wy = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++)
			{
				int nextX = wx + dx[i];
				int nextY = wy + dy[i];
				if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && lake[nextX][nextY] == 'X')
				{
					lake[nextX][nextY] = '.';
					water.push(make_pair(nextX, nextY));
				}
			}
			waterSize--;
		}
		result++;

	}



	cout << result << "\n";
	return 0;
}













//void moveSwan(int x1, int y1, int x2, int y2);
//void meltIce();



//void moveSwan(int x1,int y1,int x2,int y2)
//{
//	queue<pair<int, int>> q;
//
//	q.push(make_pair(x1, y1));
//	visited[x1][y1] = true;
//
//	while (1)
//	{
//		if (q.empty())break;
//		int curX = q.front().first;
//		int curY = q.front().second;
//		q.pop();
//		
//		if (curX == x2 && curY == y2)
//		{
//			swanCheck = true;
//			break;
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int nextX = curX + dx[i];
//			int nextY = curY + dy[i];
//			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && visited[nextX][nextY]==false && lake[nextX][nextY]!='X')
//			{
//				q.push(make_pair(nextX, nextY));
//				visited[nextX][nextY] = true;
//			}
//		}
//
//	}
//
//}
//
//void meltIce()
//{
//	queue<pair<int, int>> q;
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			if (lake[i][j] == 'X')
//			{
//				for (int z = 0; z < 4; z++)
//				{
//					int _x = i + dx[z];
//					int _y = j + dy[z];
//					if (_x >= 0 && _x < R && _y >= 0 && _y < C)
//					{
//						if (lake[_x][_y] != 'X')
//						{
//							q.push(make_pair(i, j));
//							break;
//						}
//					}
//				}
//			}
//		}
//	}
//	while (1)
//	{
//		if (q.empty())break;
//
//		int removeX = q.front().first;
//		int removeY = q.front().second;
//		q.pop();
//		lake[removeX][removeY] = '.';
//
//	}
//
//
//
//}
