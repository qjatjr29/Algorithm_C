#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// N은 도시수, M은 길의 수, K는 좀비 도시 , S는 좀비도시로부터의 거리
int N, M, K, S;
int p, q;
long long result = 10000000001;
vector<bool> visited;
vector<int> check;
queue<pair<int, int>> jombie; // 좀비 도시
vector<vector<int>> road; // 연결 도로 
void neighborJombie();
void moveToN();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M >> K >> S;
	road = vector<vector<int>>(N + 1);
	check = vector<int>(N + 1, 0); // 1 이면 q 가격
	visited = vector<bool>(N + 1, false);
	cin >> p >> q;

	for (int i = 0; i < K; i++)
	{
		int jombieCity;
		cin >> jombieCity;

		check[jombieCity] = 2;
		jombie.push(make_pair(jombieCity, 0));
	}

	for (int i = 0; i < M; i++)
	{
		int sc, dc;
		cin >> sc >> dc;
		road[sc].push_back(dc);
		road[dc].push_back(sc);
	}
	neighborJombie();
	moveToN();
	cout << result << "\n";



	return 0;
}

void neighborJombie()
{
	while (1)
	{
		if (jombie.empty())break;
		int jidx = jombie.front().first;
		int count = jombie.front().second;
		jombie.pop();

		if (count <= S && count != 0)
		{
			check[jidx] = 1;
		}
		if (count == S)continue;

		for (int i = 0; i < road[jidx].size(); i++)
		{
			int nidx = road[jidx][i];
			if (visited[nidx] == false && check[nidx] != 2)
			{
				visited[nidx] = true;
				jombie.push(make_pair(nidx, count + 1));
			}
		}
	}
}

void moveToN()
{
	priority_queue<pair<long long, int>> pq;
	pq.push(make_pair(0, 1));
	visited = vector<bool>(N + 1, false);
	visited[1] = true;

	while (1)
	{
		if (pq.empty())break;
		long long cCost = -pq.top().first;
		int cIndex = pq.top().second;

		pq.pop();

		/*	if (cIndex == N)
			{
				result = cCost;
				return;
			}*/

		for (int i = 0; i < road[cIndex].size(); i++)
		{
			int nindex = road[cIndex][i];
			if (nindex == N)
			{
				result = cCost;
				return;
			}
			if (visited[nindex] == false && check[nindex] != 2)
			{
				visited[nindex] = true;
				if (check[nindex] == 1)
				{
					pq.push(make_pair(-(cCost + q), nindex));
				}
				else
					pq.push(make_pair(-(cCost + p), nindex));
			}
		}

	}

}
