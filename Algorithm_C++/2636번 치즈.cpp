#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int R, C;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
// -1 : 외부 공기,  1 : 치즈,  0 : 내부 공기
vector<vector<int>> map;
vector<vector<bool>> visited;
int cheeseCount;
int resultTime;
int resultCount;
// 외부/내부 공기로 나누는 작업.
void firstAir();
void checkAir();
// 치즈 녹는 과정
void meltingCheese();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> R >> C;
	map = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int mapState;
			cin >> mapState;
			map[i][j] = mapState;
			if (mapState == 1)
			{
				cheeseCount++;
			}
		}
	}
	firstAir();
	while (1)
	{
		if (cheeseCount <= 0) break;
		resultTime++;
		meltingCheese();
		checkAir();
	}
	cout << resultTime << "\n";
	cout << resultCount << "\n";
	return 0;
}

void firstAir()
{
	queue<pair<int, int>> q;
	visited = vector<vector<bool>>(R + 1, vector<bool>(C + 1, false));
	map[0][0] = -1;
	visited[0][0] = true;
	q.push(make_pair(0, 0));
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

			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && visited[nextX][nextY] == false && map[nextX][nextY] == 0)
			{
				map[nextX][nextY] = -1;
				visited[nextX][nextY] = true;
				q.push(make_pair(nextX, nextY));
			}
		}

	}

}

void checkAir()
{

	queue<pair<int, int>> q;
	visited = vector<vector<bool>>(R + 1, vector<bool>(C + 1, false));
	map[0][0] = -1;
	visited[0][0] = true;
	q.push(make_pair(0, 0));
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

			if (nextX >= 0 && nextX < R && nextY >= 0 && nextY < C && visited[nextX][nextY] == false && map[nextX][nextY] != 1)
			{
				map[nextX][nextY] = -1;
				visited[nextX][nextY] = true;
				q.push(make_pair(nextX, nextY));
			}
		}

	}

}

void meltingCheese()
{
	vector<pair<int, int>> meltedCheese;

	for (int i = 1; i < R - 1; i++)
	{
		for (int j = 1; j < C - 1; j++)
		{
			// 치즈 인 경우 
			if (map[i][j] == 1)
			{
				for (int z = 0; z < 4; z++)
				{
					int checkX = i + dx[z];
					int checkY = j + dy[z];
					// 주변에 외부 공기가 있는 경우.
					if (checkX >= 0 && checkX < R && checkY >= 0 && checkY < C && map[checkX][checkY] == -1)
					{
						cheeseCount--;
						meltedCheese.push_back(make_pair(i, j));
						break;
					}
				}
			}
		}
	}
	resultCount = 0;
	for (int i = 0; i < meltedCheese.size(); i++)
	{
		int removeX = meltedCheese[i].first;
		int removeY = meltedCheese[i].second;

		map[removeX][removeY] = -1;
		resultCount++;
	}


}
