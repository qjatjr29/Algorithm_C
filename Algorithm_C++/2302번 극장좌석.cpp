#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> seat;
vector<int> VIP;
vector<int> dp;
int temp;
int result;
void sol(int n);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;
	dp = vector<int>(N + 1, 0);
	dp[0] = 1;
	dp[1] = 1;
	// dp [n] =dp[n-1]+dp[n-2]
	for (int i = 2; i <= N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 0; i < M; i++)
	{
		int number;
		cin >> number;
		VIP.push_back(number);
		seat.push_back(number - temp - 1);
		temp = number;
	}
	if (temp != N)
	{
		seat.push_back(N - temp);
	}
	result = 1;
	for (int i = 0; i < seat.size(); i++)
	{
		result = result * dp[seat[i]];
	}
	cout << result << "\n";
	return 0;
}


