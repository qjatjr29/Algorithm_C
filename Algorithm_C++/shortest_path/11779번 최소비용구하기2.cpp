#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int startCity, endCity;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int preNode[1001];
vector<int> visitedCity;
vector<int> result;
void city(int idx);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	adj = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
	visited = vector<bool>(n + 1, false);

	for (int i = 0; i < m; i++)
	{
		int sc, dc, cost;
		cin >> sc >> dc >> cost;
		adj[sc].push_back(make_pair(dc, cost));
	}
	cin >> startCity >> endCity;
	city(startCity);

	cout << result[endCity] << "\n";
	visitedCity.push_back(endCity);
	int chk = endCity;
	while (1)
	{
		chk = preNode[chk];
		visitedCity.push_back(chk);
		if (chk == startCity)break;
	}
	cout << visitedCity.size() << "\n";
	for (int i = visitedCity.size() - 1; i > 0; i--)
	{
		cout << visitedCity[i] << " ";
	}
	cout << visitedCity[0] << "\n";

	return 0;
}

void city(int idx)
{
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, idx));
	result = vector<int>(n + 1, 987654321);

	while (1)
	{

		if (pq.empty())break;
		int curNode = pq.top().second;
		int curCost = -pq.top().first;
		if (curNode == endCity)return;
		pq.pop();
		if (curCost > result[curNode])continue;

		for (int i = 0; i < adj[curNode].size(); i++)
		{
			int nNode = adj[curNode][i].first;
			int nCost = adj[curNode][i].second;
			if (result[nNode] > nCost + curCost)
			{
				result[nNode] = nCost + curCost;
				preNode[nNode] = curNode;
				pq.push(make_pair(-result[nNode], nNode));
			}
		}
	}
}
