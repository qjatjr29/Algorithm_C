#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 가장 긴 거리를 반으로 계속 나누면? --> 틀림

int N, M, L;
int result;
vector<int> _distance;
priority_queue<pair<int, int>> restarea;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N >> M >> L;

	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		_distance.push_back(number);
	}
	sort(_distance.begin(), _distance.end());
	restarea.push(make_pair(_distance[0], 1));
	for (int i = 1; i < N; i++)
	{
		int distancegap = _distance[i] - _distance[i - 1];
		restarea.push(make_pair(distancegap, 1));
	}
	restarea.push(make_pair(L - _distance[N - 1], 1));



	for (int i = 0; i < M; i++)
	{
		int maxdistance = restarea.top().first;
		int _div = restarea.top().second;
		int pushtemp = (maxdistance * _div) / (_div + 1);
		_div++;

		restarea.pop();
		restarea.push(make_pair(pushtemp, _div));


	}
	cout << restarea.top().first << "\n";

	return 0;
}