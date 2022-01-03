#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> hw;
int resultSize;
vector<int> result;
int sum;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	hw = vector<vector<int>>(1001, vector<int>());
	for (int i = 0; i < N; i++)
	{
		int d, w;
		cin >> d >> w;
		hw[d].push_back(w);
		if (hw[d].size() == 1)resultSize = max(resultSize, d);
	}
	for (int i = 1; i <= resultSize; i++)
	{
		if (hw[i].size() == 0)continue;
		sort(hw[i].begin(), hw[i].end(), greater<>());
		if (hw[i].size() > 1)
		{
			for (int j = 0; j < i; j++)
			{
				if (j == hw[i].size())break;
				int addNumber = hw[i][j];
				result.push_back(addNumber);
			}
			sort(result.begin(), result.end(), greater<>());
			while (1)
			{
				if (result.size() <= i)break;
				result.pop_back();
			}
		}
		else if (hw[i].size() == 1)
		{
			result.push_back(hw[i][0]);
		}
	}

	for (int i = 0; i < result.size(); i++)
	{
		sum += result[i];
	}
	cout << sum << "\n";



	return 0;
}