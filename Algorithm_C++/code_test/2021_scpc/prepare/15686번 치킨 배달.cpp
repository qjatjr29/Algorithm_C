#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
vector<vector<int>>map;
vector<pair<int, int>> house;
vector<pair<int, int>> store;
vector<int> numberArr;
vector<int> combIndex;
vector<vector<int>> combStore;
void combinationStore(int r, int index, int depth);
int result = 987654321;
int calcDistance(int x1, int y1, int x2, int y2);
void calcMinDist();
int main()
{

	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int number;
			cin >> number;
			if (number == 1)
			{
				house.push_back(make_pair(i, j));
			}
			else if (number == 2)
			{
				store.push_back(make_pair(i, j));
			}
			map[i][j] = number;
		}
	}
	numberArr = vector<int>(store.size(), 0);
	for (int i = 1; i <= store.size(); i++)
	{
		numberArr[i - 1] = i;
	}
	combIndex = vector<int>(M, 0);
	combinationStore(M, 0, 0);

	calcMinDist();
	cout << result << "\n";

	return 0;
}
void combinationStore(int r, int index, int depth)
{

	if (r == 0)
	{
		vector<int> temp;
		for (int i = 0; i < combIndex.size(); i++)
		{
			temp.push_back(combIndex[i]);
		}
		combStore.push_back(temp);
	}
	else if (depth == numberArr.size())return;
	else
	{
		combIndex[index] = numberArr[depth];
		combinationStore(r - 1, index + 1, depth + 1);
		combinationStore(r, index, depth + 1);
	}

}


int calcDistance(int x1, int y1, int x2, int y2)
{
	int dis = abs(x1 - x2) + abs(y1 - y2);
	return dis;
}

void calcMinDist()
{

	for (int i = 0; i < combStore.size(); i++)
	{
		int tempResult = 0;
		for (int j = 0; j < house.size(); j++)
		{
			int houseX = house[j].first;
			int houseY = house[j].second;
			int houseDist = 987654321;
			for (int z = 0; z < combStore[i].size(); z++)
			{
				int storeX = store[combStore[i][z] - 1].first;
				int storeY = store[combStore[i][z] - 1].second;
				houseDist = min(houseDist, calcDistance(houseX, houseY, storeX, storeY));
			}
			tempResult += houseDist;
		}


		result = min(result, tempResult);
	}
}
