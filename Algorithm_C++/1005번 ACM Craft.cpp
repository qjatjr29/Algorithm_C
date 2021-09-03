#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int T, N, K, W;
vector<int> building;
vector<vector<bool>> adj;
vector<int> adjCount;
vector<int> buildTime;
void input();
void build();
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		cin >> N >> K;
		input();
		cin >> W;
		build();
		cout << result << "\n";
	}

	return 0;
}

void input()
{
	building = vector<int>();
	adj = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	adjCount = vector<int>(N + 1, 0);
	buildTime = vector<int>(N + 1, 0);
	result = 0;

	for (int i = 0; i < N; i++)
	{
		int time;
		cin >> time;
		building.push_back(time);
	}
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = true;
		adjCount[b]++;
	}
}

void build()
{
	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (adjCount[i] == 0)
		{
			buildTime[i] = building[i - 1];
			q.push(i);
		}
	}

	while (1)
	{
		if (q.empty())break;
		int curIndex = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (curIndex == i)continue;
			if (adj[curIndex][i])
			{
				buildTime[i] = max(buildTime[i], buildTime[curIndex] + building[i - 1]);
				adjCount[i]--;
				if (adjCount[i] == 0)
				{
					q.push(i);
				}
			}

		}
	}
	result = buildTime[W];
}
