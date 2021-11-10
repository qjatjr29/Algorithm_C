#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int numbers[101];
long long dp[101][21];
long long sol(int index, long long result);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		numbers[i] = num;
	}
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			dp[i][j] = -1;
		}
	}

	cout << sol(1, numbers[0]) << "\n";
	return 0;
}

long long sol(int index, long long result)
{
	if (result < 0 || result>20)return 0;
	if (index == N - 1)
	{
		if (result == numbers[index])
			return 1;
		else return 0;
	}
	if (dp[index][result] != -1)return dp[index][result];

	return dp[index][result] = sol(index + 1, result - numbers[index]) + sol(index + 1, result + numbers[index]);


}
