#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> level;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	level = vector<int>(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		int score;
		cin >> score;
		level[i] = score;
	}

	for (int i = N - 1; i > 0; i--)
	{
		if (level[i] <= level[i - 1])
		{
			int gap = level[i - 1] - level[i] + 1;
			result += gap;
			level[i - 1] = level[i] - 1;
		}
	}
	cout << result << "\n";

	return 0;
}