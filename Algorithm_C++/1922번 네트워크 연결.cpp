#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<bool> visited;
vector<vector<pair<int, int>>> spanning;
int visitedCount;
int result;
void spanningTree(int start);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	visited = vector<bool>(N + 1, false);
	spanning = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		// c가 비용
		int a, b, c;
		cin >> a >> b >> c;
		spanning[a].push_back(make_pair(b, c));
		spanning[b].push_back(make_pair(a, c));
	}
	spanningTree(1);
	cout << result << "\n";

	return 0;
}


void spanningTree(int start)
{
	// (비용,위치)
	// 간선이 N-1개면 끝. 
	priority_queue<pair<int, int>> pq;
	// 처음 시작하는 정점 방문 표시
	visited[start] = true;
	// 처음 시작하는 정점에서 연결된 간선들 다 pq에 넣기
	for (int i = 0; i < spanning[start].size(); i++)
	{
		int startCost = spanning[start][i].second;
		int nextIndex = spanning[start][i].first;
		if (visited[nextIndex] == false)
		{
			pq.push(make_pair(-startCost, nextIndex));
		}
	}
	while (1)
	{
		// 간선 갯수가 N-1개면 리턴
		if (visitedCount == N - 1)return;
		if (pq.empty())break;
		int curCost = -pq.top().first;
		int curIndex = pq.top().second;
		pq.pop();
		// 이미 지난 정점이면 넘어간다.
		if (visited[curIndex])continue;
		visited[curIndex] = true;
		result += curCost;
		// 방문한 간선 늘어 남.
		visitedCount++;
		for (int i = 0; i < spanning[curIndex].size(); i++)
		{
			int plusCost = spanning[curIndex][i].second;
			int nextIndex = spanning[curIndex][i].first;
			// 지나지 않은 정점일때만 우선순위 큐에 넣어준다.
			// 일단 정점들 다 우선순위 큐에 넣어놔야한다.
			// 그래야 나중에 그 중에 가장 작은것으로 하기 떄문 ( 우선순위 큐로 가장 작은게 나옴 )
			if (visited[nextIndex] == false)
			{
				pq.push(make_pair(-plusCost, nextIndex));
			}
		}


	}
}
