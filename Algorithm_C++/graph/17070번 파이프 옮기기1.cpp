#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> map;
queue <pair<int, pair<int, int>>> pq;
void start(int x, int y);
void moveX(int x, int y);
void moveXY(int x, int y);
void moveY(int x, int y);
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			map[i][j] = number;
		}
	}
	start(0, 1);
	cout << result << "\n";

	return 0;
}

void start(int x, int y)
{

	pq.push(make_pair(1, make_pair(x, y)));

	// ������ ����  ���� : 1, ���� : 2 , �밢�� : 3 

	while (1)
	{
		if (pq.empty())break;
		int state = pq.front().first;
		int curX = pq.front().second.first;
		int curY = pq.front().second.second;
		pq.pop();
		if (state == 1)
		{
			moveX(curX, curY);
			moveXY(curX, curY);
		}
		else if (state == 2)
		{
			moveY(curX, curY);
			moveXY(curX, curY);
		}
		else
		{
			moveX(curX, curY);
			moveY(curX, curY);
			moveXY(curX, curY);
		}
	}
}

// ���η� �̵�
void moveX(int x, int y)
{
	if (y >= 0 && y + 1 < N && map[x][y + 1] == 0)
	{
		if (x == N - 1 && y + 1 == N - 1)
		{
			result++;
		}
		else {
			pq.push(make_pair(1, make_pair(x, y + 1)));
		}
	}
}
// �밢�� �̵�
void moveXY(int x, int y)
{

	if (x >= 0 && y >= 0 && y + 1 < N && x + 1 < N && map[x][y + 1] == 0 && map[x + 1][y] == 0 && map[x + 1][y + 1] == 0)
	{
		if (x + 1 == N - 1 && y + 1 == N - 1)
		{
			result++;
		}
		else {
			pq.push(make_pair(3, make_pair(x + 1, y + 1)));
		}
	}
}
// ���η� �̵�
void moveY(int x, int y)
{
	if (x >= 0 && x + 1 < N && map[x + 1][y] == 0)
	{
		if (x + 1 == N - 1 && y == N - 1)
		{
			result++;
		}
		else {
			pq.push(make_pair(2, make_pair(x + 1, y)));
		}
	}
}
