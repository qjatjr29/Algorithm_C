#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<bool>> visited;
int answer;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void rupee();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int count = 1;
	while (1)
	{
		cin >> N;
		if (N == 0)break;
		map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
		answer = 987654321;
		visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int thief;
				cin >> thief;
				map[i][j] = thief;
			}
		}
		rupee();
		cout << "Problem " << count << ": " << answer << "\n";
		count++;
	}


	return 0;
}

void rupee()
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push(make_pair(-map[0][0], make_pair(0, 0)));
	visited[0][0] = true;
	while (1)
	{
		if (pq.empty())break;

		int curRupee = -pq.top().first;
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;

		pq.pop();

		if (curX == N - 1 && curY == N - 1)
		{
			answer = min(answer, curRupee);
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nextX = curX + dx[i];
			int nextY = curY + dy[i];
			if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && visited[nextX][nextY] == false)
			{
				int nextRupee = curRupee + map[nextX][nextY];
				visited[nextX][nextY] = true;
				pq.push(make_pair(-nextRupee, make_pair(nextX, nextY)));
			}
		}

	}
}
