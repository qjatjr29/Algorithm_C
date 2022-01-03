#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int A;
vector<int> arr;
int dp[1001];
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> A;
	for (int i = 0; i < A; i++)
	{
		int number;
		cin >> number;
		arr.push_back(number);
	}

	for (int i = 0; i < arr.size(); i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int result = 0;
	for (int i = 0; i < A; i++)
	{
		result = max(result, dp[i]);
	}
	cout << result << "\n";
	return 0;
}