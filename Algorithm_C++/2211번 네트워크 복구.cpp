#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


int N, M;
vector<pair<int, int>> adj[1001];
vector<int> dist;
vector<int> answer;

void network();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;

	answer = vector<int>(N + 1, 0);
	dist = vector<int>(N + 1, 987654321);
	for (int i = 0; i < M; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		adj[start].push_back(make_pair(end, weight));
		adj[end].push_back(make_pair(start, weight));
	}

	network();
	cout << N - 1 << "\n";

	for (int i = 2; i <= N; i++)
	{
		cout << i << " " << answer[i] << "\n";
	}






	return 0;
}

void network()
{
	priority_queue<pair<int, int>> pq;

	// 경로 cost , 현재 위치
	pq.push(make_pair(0, 1));


	while (1)
	{
		if (pq.empty())break;

		int curIndex = pq.top().second;
		int curCost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < adj[curIndex].size(); i++)
		{
			int nextIndex = adj[curIndex][i].first;
			int nextCost = curCost + adj[curIndex][i].second;
			if (dist[nextIndex] > nextCost)
			{
				answer[nextIndex] = curIndex;
				dist[nextIndex] = nextCost;
				pq.push(make_pair(-nextCost, nextIndex));
			}
		}

	}


}
