#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int N, K;
bool visited[100001];
int parent[100001];
int dx[2] = { -1,1 };
void getParent(int index);
int resultTime;
vector<int> result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < 100001; i++)
	{
		parent[i] = i;
		visited[i] = false;
	}
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, N));
	visited[N] = true;
	while (1)
	{
		int cCount = -pq.top().first;
		int cX = pq.top().second;
		pq.pop();

		if (cX == K)
		{
			resultTime = cCount;
			break;
		}
		for (int i = 0; i < 2; i++)
		{
			int nx = cX + dx[i];
			if (nx >= 0 && nx < 100001 && visited[nx] == false)
			{
				visited[nx] = true;
				parent[nx] = cX;
				pq.push(make_pair(-(cCount + 1), nx));
			}
		}
		int jumpX = 2 * cX;
		if (jumpX >= 0 && jumpX < 100001 && visited[jumpX] == false)
		{
			visited[jumpX] = true;
			parent[jumpX] = cX;
			pq.push(make_pair(-(cCount + 1), jumpX));
		}
	}
	cout << resultTime << "\n";
	result.push_back(K);
	getParent(K);
	reverse(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << "\n";

	return 0;
}
void getParent(int index)
{
	if (parent[index] == index) {
		return;
	}
	result.push_back(parent[index]);
	return getParent(parent[index]);
}



