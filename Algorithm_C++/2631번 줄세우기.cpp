#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int dp[201];
vector<int> children;
void calLIS(int index);
int maxChildren;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		children.push_back(number);
		calLIS(i);
	}
	cout << N - maxChildren << "\n";

	return 0;
}

void calLIS(int index)
{
	dp[index] = 1;
	for (int i = 0; i < index; i++)
	{
		if (children[i] < children[index])
		{
			dp[index] = max(dp[index], dp[i] + 1);
			maxChildren = max(maxChildren, dp[index]);
		}
	}
}
