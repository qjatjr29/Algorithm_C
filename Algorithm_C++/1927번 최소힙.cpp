#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N;
priority_queue<int> arr;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (!arr.empty())
			{
				cout << -arr.top() << "\n";
				arr.pop();
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else
		{
			arr.push(-x);
		}
	}



	return 0;
}