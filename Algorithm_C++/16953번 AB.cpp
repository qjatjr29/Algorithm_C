#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

long long A, B;
vector<bool> visited;
void AtoB(long long start);
long long result = 987654321;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> A >> B;
	visited = vector<bool>(B + 1, false);
	AtoB(A);
	if (result == 987654321)
	{
		cout << -1 << "\n";
	}
	else cout << result << "\n";

	return 0;
}

void AtoB(long long start)
{
	priority_queue<pair<long long, long long>> pq;
	pq.push(make_pair(0, start));
	visited[start] = true;

	while (1)
	{
		if (pq.empty())break;
		long long count = -pq.top().first;
		long long curIndex = pq.top().second;

		pq.pop();
		if (curIndex == B)
		{
			result = count + 1;
			return;
		}
		if (2 * curIndex <= B && visited[2 * curIndex] == false)
		{
			visited[2 * curIndex] = true;
			pq.push(make_pair(-(count + 1), 2 * curIndex));
		}
		if (10 * curIndex + 1 <= B && visited[10 * curIndex + 1] == false)
		{
			visited[10 * curIndex + 1] == true;
			pq.push(make_pair(-(count + 1), 10 * curIndex + 1));
		}
	}

}
