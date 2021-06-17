#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
priority_queue<long long> pq;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long number;
			cin >> number;
			pq.push(-number);
			if (pq.size() > N)
			{
				pq.pop();
			}
		}
	}
	cout << -pq.top() << "\n";

	return 0;
}