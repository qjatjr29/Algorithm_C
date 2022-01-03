#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
vector<vector<int>> number;
int DIVIDEMAX = 1000000000;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	number = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		number[i][1] = 1;
	}
	for (int i = 1; i <= K; i++)
	{
		number[0][i] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 2; j <= K; j++)
		{
			for (int z = 1; z <= j; z++)
			{
				number[i][j] = (number[i][j] + number[i - 1][z]) % DIVIDEMAX;
			}

		}
	}
	cout << number[N][K] << "\n";

	return 0;
}