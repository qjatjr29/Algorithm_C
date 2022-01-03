#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int N;
stack<long long> building;
long long result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int height;
		cin >> height;
		if (i != 0)
		{
			while (1)
			{
				if (building.empty())break;
				int top = building.top();
				if (top <= height)
				{
					building.pop();
				}
				else
				{
					result += building.size();
					break;
				}
			}	
		}
		building.push(height);
	
	}

	cout << result << "\n";

	return 0;
}