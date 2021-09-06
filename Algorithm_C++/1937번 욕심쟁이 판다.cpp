#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<vector<int>> map;
priority_queue<pair<int, pair<int, int>>>pq;
vector<vector<int>> dp;
int result;
void panda();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
	dp = vector<vector<int>>(n + 1, vector<int>(n + 1, 1));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int number;
			cin >> number;
			map[i][j] = number;
			pq.push(make_pair(number, make_pair(i, j)));
		}
	}
	panda();
	cout << result << "\n";

	return 0;
}

void panda()
{
	while (1)
	{
		if (pq.empty())break;

		int curBamboo = pq.top().first;
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;

		pq.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)continue;
			if (map[nextX][nextY] > curBamboo)
			{
				dp[curX][curY] = max(dp[curX][curY], 1 + dp[nextX][nextY]);
			}
		}
		result = max(result, dp[curX][curY]);
	}
}
