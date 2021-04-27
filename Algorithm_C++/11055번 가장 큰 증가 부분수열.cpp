#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> sum;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	sum = vector<pair<int, int>>(N + 1, make_pair(0, 0));
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		// first : 수열의 값
		// second :  이 수열이 마지막 번호일때 가장 큰 증가 부분 수열의 합.
		sum[i] = make_pair(number, number);
	}

	for (int i = 1; i < N; i++)
	{
		int curSum = sum[i].second;
		int curNum = sum[i].first;
		for (int j = i - 1; j >= 0; j--)
		{
			if (curNum > sum[j].first && sum[j].second + curNum >= curSum)
			{
				sum[i].second = sum[j].second + curNum;
				curSum = sum[i].second;
			}
		}
	}
	int result = -1;
	for (int i = 0; i < sum.size(); i++)
	{
		if (result < sum[i].second)
		{
			result = sum[i].second;
		}
	}
	cout << result << "\n";
	return 0;
}