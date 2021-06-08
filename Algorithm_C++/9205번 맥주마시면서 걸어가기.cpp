#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int t;
int n;
bool check = false;
int festivalX, festivalY;
vector<bool> visited;
vector<pair<int, int>> mart;
void Festival(int start);
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		check = false;
		int homeX, homeY;
		cin >> homeX >> homeY;
		mart = vector<pair<int, int>>(n + 1);
		visited = vector<bool>(n + 1, false);
		for (int j = 0; j < n; j++)
		{
			int martX, martY;
			cin >> martX >> martY;
			mart[j] = make_pair(martX, martY);
		}

		cin >> festivalX >> festivalY;
		int homeToFestival = abs(homeX - festivalX) + abs(homeY - festivalY);
		if (homeToFestival <= 1000)
		{
			check = true;

		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (abs(homeX - mart[j].first) + abs(homeY - mart[j].second) <= 1000)
				{
					Festival(j);
				}
			}
		}
		if (check == true)
		{
			cout << "happy" << "\n";
		}
		else
		{
			cout << "sad" << "\n";
		}
	}


	return 0;
}

void Festival(int start)
{
	queue<pair<int, int>> q;
	q.push(make_pair(mart[start].first, mart[start].second));
	visited[start] = true;
	while (1)
	{
		if (q.empty())break;
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		if (abs(curX - festivalX) + abs(curY - festivalY) <= 1000)
		{
			check = true;
			break;
		}
		for (int i = 1; i < n; i++)
		{
			if (visited[i] != true && abs(curX - mart[i].first) + abs(curY - mart[i].second) <= 1000)
			{
				q.push(make_pair(mart[i].first, mart[i].second));
				visited[i] = true;
			}
		}
	}
}
