#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, S, M;
vector<int> V;
vector<vector<int>> dp;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> S >> M;
	V = vector<int>(N + 1, 0);
	dp = vector<vector<int>>(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		V[i] = num;
	}
	dp[0][S] = 1;
	int result = -1;
	for (int i = 1; i <= N; i++)
	{
		if (i == N)
		{
			for (int j = 0; j <= M; j++)
			{
				// 있는 경우
				if (dp[i - 1][j] == 1)
				{
					if (j + V[i] <= M)
					{
						result = max(result, j + V[i]);
					}
					if (j - V[i] >= 0)
					{
						result = max(result, j - V[i]);
					}
				}
			}
		}
		else
		{
			for (int j = 0; j <= M; j++)
			{
				// 있는 경우
				if (dp[i - 1][j] == 1)
				{
					if (j + V[i] <= M)
					{
						dp[i][j + V[i]] = 1;
					}
					if (j - V[i] >= 0)
					{
						dp[i][j - V[i]] = 1;
					}
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}