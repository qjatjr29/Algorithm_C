#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, K;
vector<pair<int, int>> bag;
vector<vector<int>> value;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	bag = vector<pair<int, int>>(N + 1, make_pair(0, 0));
	value = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		int w, v;
		cin >> w >> v;
		bag[i] = make_pair(w, v);
	}

	for (int i = 1; i <= N; i++)
	{
		int curWeight = bag[i].first;
		int curValue = bag[i].second;
		for (int j = 0; j <= K; j++)
		{
			if (j < curWeight)
			{
				value[i][j] = value[i - 1][j];
			}
			else
			{
				value[i][j] = max(value[i - 1][j], value[i - 1][j - curWeight] + curValue);
			}
		}
	}
	cout << value[N][K] << "\n";


	return 0;
}