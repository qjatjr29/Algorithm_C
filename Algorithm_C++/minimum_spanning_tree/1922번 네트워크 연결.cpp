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
		// c�� ���
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
	// (���,��ġ)
	// ������ N-1���� ��. 
	priority_queue<pair<int, int>> pq;
	// ó�� �����ϴ� ���� �湮 ǥ��
	visited[start] = true;
	// ó�� �����ϴ� �������� ����� ������ �� pq�� �ֱ�
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
		// ���� ������ N-1���� ����
		if (visitedCount == N - 1)return;
		if (pq.empty())break;
		int curCost = -pq.top().first;
		int curIndex = pq.top().second;
		pq.pop();
		// �̹� ���� �����̸� �Ѿ��.
		if (visited[curIndex])continue;
		visited[curIndex] = true;
		result += curCost;
		// �湮�� ���� �þ� ��.
		visitedCount++;
		for (int i = 0; i < spanning[curIndex].size(); i++)
		{
			int plusCost = spanning[curIndex][i].second;
			int nextIndex = spanning[curIndex][i].first;
			// ������ ���� �����϶��� �켱���� ť�� �־��ش�.
			// �ϴ� ������ �� �켱���� ť�� �־�����Ѵ�.
			// �׷��� ���߿� �� �߿� ���� ���������� �ϱ� ���� ( �켱���� ť�� ���� ������ ���� )
			if (visited[nextIndex] == false)
			{
				pq.push(make_pair(-plusCost, nextIndex));
			}
		}


	}
}
