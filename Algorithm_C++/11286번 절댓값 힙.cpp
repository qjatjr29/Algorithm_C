#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
priority_queue<pair<int, int>> pq;
//vector<int> result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		if (number == 0)
		{
			if (pq.empty())
			{
				//result.push_back(0);
				cout << 0 << "\n";
			}
			else
			{
				int deleteNum = -pq.top().second;
				//result.push_back(deleteNum);
				cout << deleteNum << "\n";
				pq.pop();
			}
		}
		else
		{
			int pqNum = abs(number);
			pq.push(make_pair(-pqNum, -number));
		}
	}
	/*for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\n";
	}*/

	return 0;
}