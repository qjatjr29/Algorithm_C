#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> map;
queue<pair<int, int>> cloud;
vector<pair<int, int>> movedCloud;
vector<vector<int>> tempCloud;
// move
int dx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
// crossmove
int crossx[4] = { -1,-1,1,1 };
int crossy[4] = { -1,1,-1,1 };
void moveCloud(int direction, int count);
void checkCross(int x, int y);
void checkMap(vector<vector<int>> temp);
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int rainSize;
			cin >> rainSize;
			map[i][j] = rainSize;
		}
	}
	cloud.push(make_pair(N, 1));
	cloud.push(make_pair(N, 2));
	cloud.push(make_pair(N - 1, 1));
	cloud.push(make_pair(N - 1, 2));
	for (int i = 0; i < M; i++)
	{
		int direction, count;
		cin >> direction >> count;
		moveCloud(direction, count);
		for (int j = 0; j < movedCloud.size(); j++)
		{
			checkCross(movedCloud[j].first, movedCloud[j].second);
		}
		checkMap(tempCloud);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			result += map[i][j];
		}
	}
	cout << result << "\n";
	return 0;
}

// 1단계 + 2단계 + 3단계
void moveCloud(int direction, int count)
{

	movedCloud.clear();
	tempCloud = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	int _x = 0;
	int _y = 0;
	for (int i = 0; i < count; i++)
	{
		_x += dx[direction];
		_y += dy[direction];
	}
	int size = cloud.size();
	for (int i = 0; i < size; i++)
	{
		int moveX = cloud.front().first + _x;
		int moveY = cloud.front().second + _y;
		cloud.pop();
		while (1)
		{
			if (moveX > 0 && moveX <= N)break;
			if (moveX <= 0)
			{
				moveX += N;
			}
			else if (moveX > N)
			{
				moveX -= N;
			}
		}
		while (1)
		{
			if (moveY > 0 && moveY <= N)break;
			if (moveY <= 0)
			{
				moveY += N;
			}
			else if (moveY > N)
			{
				moveY -= N;
			}
		}
		movedCloud.push_back(make_pair(moveX, moveY));
		tempCloud[moveX][moveY] = 1;
		map[moveX][moveY] += 1;
	}
}

// 4단계
void checkCross(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nextX = x + crossx[i];
		int nextY = y + crossy[i];
		if (nextX > 0 && nextX <= N && nextY > 0 && nextY <= N && map[nextX][nextY] > 0)
		{
			map[x][y]++;
		}
	}
}

// 5단계
void checkMap(vector<vector<int>>temp)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// 구름이 사라진 칸이 아닌 경우
			if (map[i][j] >= 2 && temp[i][j] == 0)
			{
				map[i][j] -= 2;
				cloud.push(make_pair(i, j));
			}
		}
	}
}
