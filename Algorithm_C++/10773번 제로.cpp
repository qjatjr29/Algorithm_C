#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int K;
stack<int> money;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int cost;
		cin >> cost;
		if (cost == 0)
		{
			money.pop();
		}
		else
		{
			money.push(cost);
		}
	}
	if (money.empty())
	{
		cout << 0 << "\n";
	}
	else
	{
		while (1)
		{
			if (money.empty())break;
			int _cost = money.top();
			result += _cost;
			money.pop();
		}
		cout << result << "\n";
	}

	return 0;
}