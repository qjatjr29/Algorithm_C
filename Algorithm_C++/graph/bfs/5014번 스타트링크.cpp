#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int F, S, G, U, D;

vector<bool> visited;
bool checkArrive = false;
int result;
void elevator();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> F >> S >> G >> U >> D;

	visited = vector<bool>(F + 1, false);

	elevator();
	if (checkArrive)
	{
		cout << result << "\n";
	}
	else
	{
		cout << "use the stairs" << "\n";
	}


	return 0;
}

void elevator()
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, S));
	visited[S] = true;
	if (S == G)
	{
		result = 0;
		checkArrive = true;
		return;
	}
	while (1)
	{
		if (pq.empty())break;

		int curFloor = pq.top().second;
		int curCount = -pq.top().first;
		pq.pop();
		int upFloor = curFloor + U;
		int downFloor = curFloor - D;

		if (upFloor > 0 && upFloor <= F && visited[upFloor] == false)
		{
			if (upFloor == G)
			{
				result = curCount + 1;
				checkArrive = true;
				return;
			}
			visited[upFloor] = true;
			pq.push(make_pair(-(curCount + 1), upFloor));
		}

		if (downFloor > 0 && downFloor <= F && visited[downFloor] == false)
		{
			if (downFloor == G)
			{
				result = curCount + 1;
				checkArrive = true;
				return;
			}
			visited[downFloor] = true;
			pq.push(make_pair(-(curCount + 1), downFloor));
		}

	}

}
