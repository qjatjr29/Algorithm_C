#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, L;
priority_queue<int> water;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		water.push(-number);
	}
	while (1)
	{
		if (water.empty())break;
		result++;
		int curPosition = -water.top();
		int width = curPosition + (L - 1);
		water.pop();
		while (1)
		{
			if (water.empty())break;
			int top = -water.top();
			if (top > width)break;
			water.pop();
		}

	}

	cout << result << "\n";


	return 0;
}