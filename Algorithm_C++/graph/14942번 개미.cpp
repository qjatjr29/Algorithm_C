#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int n;
vector<int> energy;
vector<vector<pair<int, int>>> path;
vector<int> preRoom;
vector<int> roomEnergy;
vector<bool> visited;
void ant(int idx);
void antNumber();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	energy = vector<int>(n + 1, 0);
	preRoom = vector<int>(n + 1);
	roomEnergy = vector<int>(n + 1);
	path = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
	visited = vector<bool>(n + 1, false);
	for (int i = 1; i <= n; i++)
	{
		int number;
		cin >> number;
		energy[i] = number;
		//preRoom[i] = i;
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		path[a].push_back(make_pair(b, c));
		path[b].push_back(make_pair(a, c));
	}
	ant(1);
	antNumber();

	return 0;
}

void ant(int idx)
{

	visited[idx] = true;

	for (int i = 0; i < path[idx].size(); i++)
	{
		int nextIndex = path[idx][i].first;
		int nextEnergy = path[idx][i].second;
		if (visited[nextIndex])continue;
		preRoom[nextIndex] = idx;
		roomEnergy[nextIndex] = nextEnergy;
		ant(nextIndex);
	}

}

void antNumber()
{
	for (int i = 1; i <= n; i++)
	{
		int answer = i;
		int curEnergy = energy[i];
		while (1)
		{
			if (answer == 1)break;
			if (curEnergy < roomEnergy[answer])break;

			curEnergy -= roomEnergy[answer];
			answer = preRoom[answer];
		}
		cout << answer << "\n";
	}
}
