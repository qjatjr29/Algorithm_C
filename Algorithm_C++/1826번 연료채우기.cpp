#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N, L, P;
//priority_queue<pair<int, int>> fuel;
vector<pair<int, int>> fuel;
int result;

void departure();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		fuel.push_back(make_pair(a, b));

	}
	sort(fuel.begin(), fuel.end());

	cin >> L >> P;
	departure();

	cout << result << "\n";

	return 0;
}


void departure()
{
	priority_queue<int> pq;

	int idx = 0;
	int curFuel = P;


	while (1)
	{

		if (curFuel >= L)break;

		while (1)
		{
			if (idx >= N || fuel[idx].first > curFuel)break;
			pq.push(fuel[idx].second);
			idx++;
		}
		if (pq.empty())
		{
			result = -1;
			break;
		}
		curFuel += pq.top();
		pq.pop();
		result++;

	}


}
