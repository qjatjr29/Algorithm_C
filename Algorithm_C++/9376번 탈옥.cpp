#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int t, h, w;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<char>> map;
vector<pair<int, int>> people;
vector<vector<bool>> visited;
int doorCount[3][103][103];
long long result = 987654321;
void escape();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> t;
	for (int testcase = 0; testcase < t; testcase++)
	{
		cin >> h >> w;
		result = 987654321;
		map = vector<vector<char>>(h + 2, vector<char>(w + 2, '.'));
		people = vector<pair<int, int>>();
		people.push_back(make_pair(0, 0));
		for (int i = 1; i <= h; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= s.size(); j++)
			{
				map[i][j] = s[j - 1];
				if (s[j - 1] == '$')
				{
					people.push_back(make_pair(i, j));
				}
			}
		}
		escape();
		cout << result << "\n";
	}


	return 0;
}


void escape()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j <= h + 1; j++)
		{
			for (int z = 0; z <= w + 1; z++)
			{
				doorCount[i][j][z] = 987654321;
			}
		}
	}


	for (int i = 0; i < 3; i++)
	{
		visited = vector<vector<bool>>(h + 2, vector<bool>(w + 2, false));
		priority_queue < pair<int, pair<int, int>>> pq;

		pq.push(make_pair(0, make_pair(people[i].first, people[i].second)));
		doorCount[i][people[i].first][people[i].second] = 0;
		visited[people[i].first][people[i].second] = true;
		while (1)
		{
			if (pq.empty())break;
			int curX = pq.top().second.first;
			int curY = pq.top().second.second;
			int curDoorCount = -pq.top().first;
			pq.pop();

			for (int j = 0; j < 4; j++)
			{
				int nextX = curX + dx[j];
				int nextY = curY + dy[j];
				int nextCount = curDoorCount;

				if (nextX<0 || nextX >h + 1 || nextY<0 || nextY>w + 1)
				{
					continue;
				}

				if (visited[nextX][nextY] == true || map[nextX][nextY] == '*')continue;

				if (map[nextX][nextY] == '#')nextCount++;

				if (doorCount[i][nextX][nextY] > nextCount)
				{
					doorCount[i][nextX][nextY] = nextCount;
					pq.push(make_pair(-nextCount, make_pair(nextX, nextY)));
					visited[nextX][nextY] = true;
				}

			}
		}

	}

	for (int j = 1; j <= h; j++)
	{
		for (int z = 1; z <= w; z++)
		{
			if (map[j][z] == '*')continue;
			long long temp = 0;
			for (int k = 0; k < 3; k++)
			{
				temp += doorCount[k][j][z];
			}
			if (map[j][z] == '#') temp -= 2;
			result = min(result, temp);
		}
	}

}
