#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int k, p, q;
int kx[8] = { -1,-2,-1,-2,1,2,1,2 };
int ky[8] = { -2,-1,2,1,-2,-1,2,1 };
int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };
int result;
queue<pair<int, int>> knight;
queue<pair<int, int>> queen;
vector<vector<bool>> chessBoard;
vector<vector<int>> map;
void moving(int d, int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	result = n * m;
	chessBoard = vector<vector<bool>>(n + 1, vector<bool>(m + 1, false));
	map = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		chessBoard[x][y] = true;
		result--;
		queen.push(make_pair(x, y));
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		chessBoard[x][y] = true;
		result--;
		knight.push(make_pair(x, y));
	}
	cin >> p;
	for (int i = 0; i < p; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
		chessBoard[x][y] = true;
		result--;
	}

	while (1)
	{
		if (knight.empty())break;
		int knightX = knight.front().first;
		int knightY = knight.front().second;
		knight.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = knightX + kx[i];
			int ny = knightY + ky[i];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m)continue;
			if (map[nx][ny] == 1)continue;
			if (chessBoard[nx][ny] == false)
			{
				chessBoard[nx][ny] = true;
				result--;
			}
		}
	}
	while (1)
	{
		if (queen.empty())break;
		int queenX = queen.front().first;
		int queenY = queen.front().second;
		queen.pop();
		for (int i = 0; i < 8; i++)
		{
			moving(i, queenX, queenY);
		}

	}

	cout << result << "\n";



	return 0;
}

void moving(int d, int x, int y)
{

	while (1)
	{
		x = x + dx[d];
		y = y + dy[d];
		if (x <= 0 || x > n || y <= 0 || y > m)break;
		if (map[x][y] == 1)break;

		if (chessBoard[x][y] == false)
		{
			chessBoard[x][y] = true;
			result--;
		}
	}
}

