#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int V;
int maxV;
vector<vector<pair<int, int>>> adj;
vector<bool> visited;
int result;
void calcDiameter(int idx, int diameter);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> V;
	adj = vector<vector<pair<int, int>>>(V + 1);

	visited = vector<bool>(V + 1, false);
	for (int i = 0; i < V; i++)
	{
		int vNum;
		cin >> vNum;
		while (1)
		{
			int connectV;
			cin >> connectV;
			if (connectV == -1)break;
			int connectCost;
			cin >> connectCost;
			adj[vNum].push_back(make_pair(connectV, connectCost));
		}
	}



	calcDiameter(1, 0);
	visited = vector<bool>(V + 1, false);
	calcDiameter(maxV, 0);
	cout << result << "\n";

	return 0;
}



void calcDiameter(int idx, int diameter)
{
	if (visited[idx])return;

	if (result < diameter)
	{
		result = diameter;
		maxV = idx;
	}

	visited[idx] = true;

	for (int i = 0; i < adj[idx].size(); i++)
	{
		int nextIndex = adj[idx][i].first;
		int nextDiameter = diameter + adj[idx][i].second;
		if (visited[nextIndex] == false)
		{
			calcDiameter(nextIndex, nextDiameter);
		}
	}
}
