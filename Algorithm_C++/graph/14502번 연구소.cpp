#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[9][9];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> virus;
vector<pair<int, int>> emptySpace;
bool visited[9][9];
bool check[65];
void combination(int idx, int n, int r);
void infect();
int temp;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int state;
			cin >> state;
			map[i][j] = state;
			if (state == 0)
			{
				temp++;
				emptySpace.push_back(make_pair(i, j));
			}
			if (state == 2)
			{
				virus.push(make_pair(i, j));
			}
		}
	}
	combination(0, 0, 3);
	cout << result << "\n";


	return 0;
}

void combination(int idx, int n, int r)
{

	if (n == r)
	{
		int tempArray[3];
		int tempIdx = 0;
		for (int i = 0; i < emptySpace.size(); i++)
		{
			if (tempIdx == 3)break;
			if (check[i] == true)
			{
				tempArray[tempIdx] = i;
				tempIdx++;
				int tempx = emptySpace[i].first;
				int tempy = emptySpace[i].second;
				map[tempx][tempy] = 1;
			}
		}
		infect();
		for (int i = 0; i < 3; i++)
		{
			int tempx = emptySpace[tempArray[i]].first;
			int tempy = emptySpace[tempArray[i]].second;
			map[tempx][tempy] = 0;
		}
		return;
	}

	for (int i = idx; i < emptySpace.size(); i++)
	{
		if (check[i] == true)continue;
		check[i] = true;
		combination(i, n + 1, r);
		check[i] = false;
	}
}

void infect()
{
	for (int i = 0; i < 9; i++)
	{
		memset(visited[i], false, sizeof(visited[i]));
	}

	int _temp = temp - 3;
	queue<pair<int, int>> virusTemp = virus;
	while (1)
	{
		if (virusTemp.empty())break;
		int curx = virusTemp.front().first;
		int cury = virusTemp.front().second;
		virusTemp.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				_temp--;
				virusTemp.push(make_pair(nx, ny));
			}
		}

	}

	result = max(result, _temp);
}
