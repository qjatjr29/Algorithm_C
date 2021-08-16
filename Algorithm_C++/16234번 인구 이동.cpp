#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

int N, L, R;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool chk = false;
vector<vector<pair<int, int>>> sharedNation;
vector<vector<int>> nation;
vector<vector<bool>> visited;
int result;
bool checkCondition(int curX, int curY, int nextX, int nextY);
void openBorder(int x, int y, int count);
void calcPeople();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> L >> R;

	nation = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int people;
			cin >> people;
			nation[i][j] = people;
		}
	}
	int count = 0;
	while (1)
	{
		chk = false;
		count = 0;
		visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
		sharedNation = vector<vector<pair<int, int>>>(N * N, vector<pair<int, int>>());
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == false)
				{
					openBorder(i, j, count);
					if (sharedNation[count].size() > 1)
					{
						count++;
					}
					else
					{
						sharedNation[count].clear();
					}
				}

			}
		}
		if (chk == false)
		{
			break;
		}
		else
		{
			calcPeople();
			result++;
		}
	}
	cout << result << "\n";
	return 0;
}

bool checkCondition(int curX, int curY, int nextX, int nextY)
{
	int curPeople = nation[curX][curY];
	int nextPeople = nation[nextX][nextY];

	if (abs(curPeople - nextPeople) >= L && abs(curPeople - nextPeople) <= R)
	{
		return true;
	}
	else return false;
}

void openBorder(int x, int y, int count)
{
	visited[x][y] = true;
	queue<pair<int, int>> q;
	sharedNation[count].push_back(make_pair(x, y));
	q.push(make_pair(x, y));
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

			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && visited[nextX][nextY] == false)
			{
				if (checkCondition(curX, curY, nextX, nextY))
				{
					q.push(make_pair(nextX, nextY));
					visited[nextX][nextY] = true;
					sharedNation[count].push_back(make_pair(nextX, nextY));
					chk = true;
				}
			}
		}

	}


}

void calcPeople()
{

	for (int i = 0; i < N * N; i++)
	{
		if (sharedNation[i].size() > 1)
		{
			int temp = 0;
			for (int j = 0; j < sharedNation[i].size(); j++)
			{
				temp += nation[sharedNation[i][j].first][sharedNation[i][j].second];
			}
			temp = temp / sharedNation[i].size();
			for (int j = 0; j < sharedNation[i].size(); j++)
			{
				nation[sharedNation[i][j].first][sharedNation[i][j].second] = temp;
			}
		}
	}


}
