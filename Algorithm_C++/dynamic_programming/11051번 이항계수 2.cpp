#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, K;
const int divide = 10007;
vector<vector<long long>> store;


// 파스칼 공식 이용

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	store = vector<vector<long long>>(N + 1, vector<long long>(N + 1, 1));
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)store[i][j] = i;
			else if (j == i)store[i][j] = 1;
			else
			{
				store[i][j] = ((store[i - 1][j - 1] + store[i - 1][j]) % divide);
			}
		}
	}
	cout << store[N][K] << "\n";

	return 0;
}