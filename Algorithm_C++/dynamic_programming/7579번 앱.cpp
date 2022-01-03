#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<int> memory;
vector<int> cost;
int dp[10001];
int costSum;
void app();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	memory = vector<int>(N + 1, 0);
	cost = vector<int>(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		int memoryCapacity;
		cin >> memoryCapacity;
		memory[i] = memoryCapacity;
	}
	for (int i = 0; i < N; i++)
	{
		int memoryCost;
		cin >> memoryCost;
		costSum += memoryCost;
		cost[i] = memoryCost;
	}
	app();
	for (int i = 0; i < 10001; i++)
	{
		if (dp[i] >= M)
		{
			cout << i << "\n";
			break;
		}
	}

	return 0;
}

void app()

{
	for (int i = 0; i < N; i++)
	{
		int indexMemory = memory[i];
		int indexCost = cost[i];

		for (int j = costSum; j >= 0; j--)
		{
			//범위 넘어간 경우.
			if (j < indexCost)break;
			// 최소의 비용으로 최대의 메모리 저장
			dp[j] = max(dp[j], dp[j - indexCost] + indexMemory);
		}

	}
}
