#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<bool> visited;
int result = 987654321;
void find(int start);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;

	visited = vector<bool>(100001, false);
	find(N);
	cout << result << "\n";
	return 0;
}

void find(int start)
{
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start));
	while (1)
	{
		if (q.empty())break;
		int cost = -q.top().first;
		int index = q.top().second;
		q.pop();
		if (index == K)
		{
			result = min(result, cost);
			continue;
		}
		visited[index] = true;
		if (index > K)
		{
			if (index - 1 >= 0 && visited[index - 1] == false)
			{
				q.push(make_pair(-(cost + 1), index - 1));
			}
		}
		else
		{
			if (index - 1 >= 0 && visited[index - 1] == false)
			{
				q.push(make_pair(-(cost + 1), index - 1));
			}
			if (index + 1 <= 100000 && visited[index + 1] == false)
			{
				q.push(make_pair(-(cost + 1), index + 1));
			}
			if (index * 2 <= 100000 && visited[index * 2] == false)
			{
				q.push(make_pair(-(cost + 1), index * 2));
			}
		}
	}
}
