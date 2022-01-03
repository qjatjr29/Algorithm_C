#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K, X;
vector<vector<int>> city;
vector<bool> visited;
vector<int> result;
void moveCity(int startCity);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M >> K >> X;
	city = vector<vector<int>>(N + 1, vector<int>());
	visited = vector<bool>(N + 1, false);
	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		city[start].push_back(end);
	}
	moveCity(X);
	if (result.size() == 0)
	{
		cout << -1 << "\n";
	}
	else
	{
		sort(result.begin(), result.end());
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << "\n";
		}
	}

	return 0;
}

void moveCity(int startCity)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, startCity));
	visited[startCity] = true;
	while (1)
	{
		if (pq.empty())break;
		int distance = -pq.top().first;
		int index = pq.top().second;

		pq.pop();
		for (int i = 0; i < city[index].size(); i++)
		{
			int nextCity = city[index][i];
			if (visited[nextCity] == false)
			{
				if (distance + 1 == K)
				{
					visited[nextCity] = true;
					result.push_back(nextCity);
				}
				else
				{
					visited[nextCity] = true;
					pq.push(make_pair(-(distance + 1), nextCity));
				}
			}
		}

	}

}
