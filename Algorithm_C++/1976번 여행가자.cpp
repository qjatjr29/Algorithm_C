//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//
//int N, M;
//vector<vector<int>> adj;
//queue<int> plan;
//vector<bool> visited;
//bool chk;
//void goTocity(int index,int findIndex);
//int main()
//{
//	cin.tie(NULL);
//	cin.sync_with_stdio(false);
//	cin >> N >> M;
//	adj = vector<vector<int>>(N + 1, vector<int>());
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			int connect;
//			cin >> connect;
//			if (connect == 1)
//			{
//				adj[i].push_back(j);
//				adj[j].push_back(i);
//			}
//		}
//	}
//	for (int i = 0; i < M; i++)
//	{
//		int cityNumber;
//		cin >> cityNumber;
//		plan.push(cityNumber);
//	}
//	int startCity = plan.front();
//	plan.pop();
//	chk = true;
//	while (1)
//	{
//		if (plan.empty())break;
//		chk = false;
//		visited = vector<bool>(N + 1, false);
//		int findCity = plan.front();
//		plan.pop();
//		goTocity(startCity, findCity);
//		startCity = findCity;
//	}
//	if (chk == true)
//	{
//		cout << "YES" << "\n";
//	}
//	else cout << "NO" << "\n";
//
//	return 0;
//}
//
//void goTocity(int index,int findIndex)
//{
//	queue<int> q;
//	q.push(index);
//	visited[index] = true;
//	while (1)
//	{
//		if (q.empty())break;
//
//		int curIndex = q.front();
//		if (curIndex == findIndex)
//		{
//			chk = true;
//			break;
//		}
//		q.pop();
//		for (int i = 0; i < adj[curIndex].size(); i++)
//		{
//			int next = adj[curIndex][i];
//			if (visited[next] == false)
//			{
//				visited[next] = true;
//				q.push(next);
//			}
//		}
//	}
//
//
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int parent[201];
int Find(int x);
int Union(int x, int y);
queue<int> plan;
bool chk;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;

	for (int i = 1; i < 201; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int state;
			cin >> state;
			if (state == 1)Union(i, j);
		}
	}
	int startCity;
	chk = true;
	for (int i = 0; i < M; i++)
	{
		int cityNumber;
		cin >> cityNumber;
		if (i != 0)
		{
			int a = Find(startCity);
			int b = Find(cityNumber);
			if (a == b)chk = true;
			else chk = false;
		}
		if (chk == false)break;
		startCity = cityNumber;
	}

	if (chk)cout << "YES" << "\n";
	else cout << "NO" << "\n";

	return 0;
}

int Find(int x)
{
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}

int Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)
	{
		if (x > y) parent[y] = x;
		else parent[x] = y;
	}
	return 0;
}
