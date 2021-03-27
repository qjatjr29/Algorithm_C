#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int dp[101][12];
const int MAXNUM = 1000000000;
long long result;
int main()
{
	cin >> N;
	// dp[0][2] ~ dp[0][10] : 1  // 1로 끝나는 값 ~ 9로 끝나는 값 저장.
	for (int i = 2; i < 11; i++)
	{
		dp[0][i] = 1;
		result += 1;
	}
	if (N > 1)
	{
		result = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < 11; j++) // 0로 끝나는 값 ~ 9로 끝나는 값.
			{
				dp[i][j] = (dp[i - 1][j - 1] % MAXNUM + dp[i - 1][j + 1] % MAXNUM) % MAXNUM;
			}
		}
		for (int i = 1; i < 11; i++)
		{
			result = (result + dp[N - 1][i]) % MAXNUM;
		}

	}
	cout << result << "\n";


	return 0;
}