#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> coin;
vector<int> cost;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	coin = vector<int>(N + 1, 0);
	cost = vector<int>(K + 1, 987654321);
	for (int i = 1; i <= N; i++)
	{
		int number;
		cin >> number;
		coin[i] = number;
		cost[number] = 1;
	}
	sort(coin.begin(), coin.end());
	for (int i = 1; i <= K; i++)
	{
		int maxIndex = -1;
		bool check = false;
		for (int j = N; j > 0; j--)
		{
			if (coin[j] < i)
			{
				maxIndex = j;
				break;
			}
			else if (coin[j] == i)
			{
				check = true;
				break;
			}
		}
		if (check == true)continue;
		if (maxIndex == -1)
			cost[i] = -1;
		else
		{
			for (int j = 1; j <= maxIndex; j++)
			{
				if (cost[i - coin[j]] == -1 || i - coin[j] <= 0)
				{
					continue;
				}
				int temp = cost[coin[j]] + cost[i - coin[j]];
				cost[i] = min(cost[i], temp);
			}
			if (cost[i] == 987654321)cost[i] = -1;
		}
	}
	cout << cost[K] << "\n";

	return 0;
}