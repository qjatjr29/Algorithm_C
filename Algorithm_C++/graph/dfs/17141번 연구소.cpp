#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<pair<int, int>> canVirus;
vector<pair<int, int>> Virus;
bool visited[51][51];
bool choiceVirus[11];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ans = 987654321;
void searchVirus();
void Combination(int count, int index);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			map[i][j] = number;
			if (number == 2)
			{
				canVirus.push_back(make_pair(i, j));
			}
		}
	}
	Combination(0, 0);
	if (ans == 987654321)
	{
		cout << -1 << "\n";
	}
	else cout << ans << "\n";



	return 0;
}

void searchVirus()
{
	queue<pair<int, int>> temp;
	for (int i = 0; i < Virus.size(); i++)
	{
		int x = Virus[i].first;
		int y = Virus[i].second;
		temp.push(make_pair(x, y));
		visited[x][y] = true;
	}
	int result = 0;
	while (temp.empty() == 0)
	{

		int size = temp.size();
		for (int i = 0; i < size; i++)
		{
			int x = temp.front().first;
			int y = temp.front().second;
			temp.pop();
			for (int i = 0; i < 4; i++)
			{
				int moveX = x + dx[i];
				int moveY = y + dy[i];
				if (moveX >= 0 && moveY >= 0 && moveX < N && moveY < N)
				{
					if (visited[moveX][moveY] == false && map[moveX][moveY] != 1)
					{
						visited[moveX][moveY] = true;
						temp.push(make_pair(moveX, moveY));
					}
				}
			}
		}
		if (temp.size() != 0)result++;

	}
	bool _check = true;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1)continue;
			if (visited[i][j] == false)
			{
				_check = false;
				break;
			}
		}
	}
	if (_check)
	{
		ans = min(ans, result);
	}
	return;
}

void Combination(int count, int index)
{
	if (count == M)
	{
		memset(visited, false, sizeof(visited));
		searchVirus();
		return;
	}
	for (int i = index; i < canVirus.size(); i++)
	{
		if (choiceVirus[i] == true)continue;
		choiceVirus[i] = true;
		Virus.push_back(canVirus[i]);
		Combination(count + 1, i);
		Virus.pop_back();
		choiceVirus[i] = false;
	}
}
