#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int N;
const int MAXNUM = 1000000000;
int dp[1000001];


int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N;
	int temp = abs(N);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < temp + 1; i++)
	{
		dp[i] = (dp[i - 1] % MAXNUM + dp[i - 2] % MAXNUM) % MAXNUM;
	}
	if (N < 0)
	{
		if (temp % 2 == 0)
		{
			cout << "-1" << "\n";
			cout << dp[temp] << "\n";
		}
		else
		{
			cout << "1" << "\n";
			cout << dp[temp] << "\n";
		}
	}
	else if (N > 0)
	{
		cout << "1" << "\n";
		cout << dp[N] << "\n";
	}
	else
	{
		cout << "0" << "\n";
		cout << "0" << "\n";
	}
	return 0;
}


