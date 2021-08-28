#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int m, n, k;
int result = 987654321;
int sx, sy, dx, dy;
vector<pair<pair<int, int>, pair<int, int>>> bus;
vector<bool> visited;
// 처음 시작할 수 있는 버스들 
vector<int> startBus;
void firstBus();
void Bus(int busNum);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> m >> n >> k;

	bus = vector<pair<pair<int, int>, pair<int, int>>>(k + 1);

	for (int i = 0; i < k; i++)
	{
		int number, _sx, _sy, _dx, _dy;
		cin >> number >> _sx >> _sy >> _dx >> _dy;
		// 수직인 경우
		if (_sx == _dx)
		{
			bus[number] = make_pair(make_pair(1, _sx), make_pair(min(_sy, _dy), max(_sy, _dy)));
		}
		// 수평으로 이동하는 경우.
		else if (_sy == _dy)
		{
			bus[number] = make_pair(make_pair(2, _sy), make_pair(min(_sx, _dx), max(_sx, _dx)));
		}

	}

	firstBus();
	for (int i = 0; i < startBus.size(); i++)
	{
		Bus(startBus[i]);
	}

	cout << result << "\n";


	return 0;
}

void firstBus()
{
	cin >> sx >> sy >> dx >> dy;

	for (int i = 1; i <= k; i++)
	{
		int busState = bus[i].first.first;

		// 수직
		if (busState == 1)
		{
			int _x = bus[i].first.second;
			int busSy = bus[i].second.first;
			int busDy = bus[i].second.second;
			// 범위 안에 있는 경우.
			if (_x == sx && busSy <= sy && sy <= busDy)
			{
				startBus.push_back(i);
			}
		}

		// 수평
		else
		{
			int _y = bus[i].first.second;
			int busSx = bus[i].second.first;
			int busDx = bus[i].second.second;
			if (_y == sy && busSx <= sx && sx <= busDx)
			{
				startBus.push_back(i);
			}
		}
	}

}

void Bus(int busNum)
{
	priority_queue<pair<int, int>> pq;
	visited = vector<bool>(k + 1, false);
	visited[busNum] = true;
	pq.push(make_pair(-1, busNum));

	while (1)
	{
		if (pq.empty())break;

		int busCount = -pq.top().first;
		int curBusNum = pq.top().second;

		int busState = bus[curBusNum].first.first;
		int busPosition = bus[curBusNum].first.second;
		int busD1 = bus[curBusNum].second.first;
		int busD2 = bus[curBusNum].second.second;

		pq.pop();

		// 수직 이동
		if (busState == 1)
		{
			// 범위 안에 도착지가 있는 경우
			if (dx == busPosition && busD1 <= dy && dy <= busD2)
			{
				result = min(result, busCount);
				return;
				break;
			}
			for (int i = 1; i <= k; i++)
			{
				if (visited[i] == true)continue;
				int nextBusState = bus[i].first.first;
				int nextBusPosition = bus[i].first.second;
				int nextBusD1 = bus[i].second.first;
				int nextBusD2 = bus[i].second.second;

				// 다음 버스가 수직으로 이동

				if (nextBusState == 1)
				{
					// 다음 버스 탈 수 없는 경우
					if (nextBusPosition != busPosition || busD1 > nextBusD2 || busD2 < nextBusD1)
					{
						continue;
					}
					visited[i] = true;
					pq.push(make_pair(-(busCount + 1), i));
				}

				//  다음 버스가 수평으로 이동
				else
				{
					// 다음 버스 탈 수 없는 경우
					if (busD2<nextBusPosition || busD1>nextBusPosition || nextBusD1 > busPosition || nextBusD2 < busPosition)
					{
						continue;
					}
					visited[i] = true;
					pq.push(make_pair(-(busCount + 1), i));
				}
			}
		}
		// 수평으로 이동
		else if (busState == 2)
		{
			// 범위 안에 도착지가 있는 경우
			if (dy == busPosition && busD1 <= dx && dx <= busD2)
			{
				result = min(result, busCount);
				return;
				break;
			}
			for (int i = 1; i <= k; i++)
			{
				if (visited[i] == true)continue;
				int nextBusState = bus[i].first.first;
				int nextBusPosition = bus[i].first.second;
				int nextBusD1 = bus[i].second.first;
				int nextBusD2 = bus[i].second.second;

				// 다음 버스가 수직으로 이동

				if (nextBusState == 1)
				{
					// 다음 버스 탈 수 없는 경우
					if (busD2<nextBusPosition || busD1>nextBusPosition || nextBusD1 > busPosition || nextBusD2 < busPosition)
					{
						continue;
					}
					visited[i] = true;
					pq.push(make_pair(-(busCount + 1), i));

				}

				//  다음 버스가 수평으로 이동
				else
				{
					// 다음 버스 탈 수 없는 경우
					if (nextBusPosition != busPosition || busD1 > nextBusD2 || busD2 < nextBusD1)
					{
						continue;
					}
					visited[i] = true;
					pq.push(make_pair(-(busCount + 1), i));
				}
			}
		}

	}
}
