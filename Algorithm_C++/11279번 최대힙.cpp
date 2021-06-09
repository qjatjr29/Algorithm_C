#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
priority_queue<int> arr;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int inputNum;
		cin >> inputNum;
		if (inputNum == 0)
		{
			if (arr.empty())
			{
				cout << 0 << "\n";

			}
			else
			{
				int outputNum = arr.top();
				cout << outputNum << "\n";

				arr.pop();
			}
		}
		else
		{
			arr.push(inputNum);
		}
	}



	return 0;
}