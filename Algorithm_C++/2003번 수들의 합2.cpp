#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long M;
vector<int> arr;
long long result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	arr = vector<int>(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		arr[i] = number;
	}
	int low = 0;
	int high = 0;
	int sum = 0;
	while (1)
	{
		if (sum > M)
		{
			sum -= arr[low++];
		}
		else if (high == N)break;
		else sum += arr[high++];
		if (sum == M)result++;
	}
	cout << result << "\n";
	return 0;
}