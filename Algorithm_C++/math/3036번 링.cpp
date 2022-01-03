#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<int> ring;
vector<pair<int, int>> result;
int GCD(int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		ring.push_back(number);
	}
	for (int i = 1; i < N; i++)
	{
		int div = GCD(ring[0], ring[i]);
		result.push_back(make_pair(ring[0] / div, ring[i] / div));
	}
	for (int i = 0; i < N - 1; i++)
	{
		cout << result[i].first << "/" << result[i].second << "\n";
	}
	return 0;
}

int GCD(int x, int y)
{
	int temp;
	while (1)
	{
		if (y == 0)break;
		temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}
