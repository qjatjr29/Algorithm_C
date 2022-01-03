#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N;
int cow[11];
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= 10; i++)
	{
		cow[i] = -1;
	}
	for (int i = 0; i < N; i++)
	{
		int cNum, state;
		cin >> cNum >> state;
		if (cow[cNum] == -1)
		{
			cow[cNum] = state;
		}
		else if (cow[cNum] != state)
		{
			cow[cNum] = state;
			result++;
		}
	}
	cout << result << "\n";

	return 0;
}