#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
vector < vector<pair<int, int>>> city;
bool visited[10001];
int startCity, endCity;
int result;
void pathBinary();
int _path(int curCost);
//void _path(int curIndex, int curCost);
int MAXCost;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	//visited = vector<bool>(N + 1, false);
	city.assign(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		int a_city, b_city, cost;
		cin >> a_city >> b_city >> cost;

		city[a_city].push_back(make_pair(b_city, cost));
		city[b_city].push_back(make_pair(a_city, cost));
		MAXCost = max(MAXCost, cost);
	}
	cin >> startCity >> endCity;
	pathBinary();
	cout << result << "\n";
	//cout << result.top() << "\n";


	return 0;
}

// 이방법 틀림.
/*
void _path(int curIndex,int curCost)
{
	// 이미 방문 한 경우
	if (visited[curIndex])return;
	//도착한 경우
	if (curIndex == endCity)
	{
		result = max(result,curCost);
		//result.push(curCost);
		return;
	}
	visited[curIndex] = true;
	for (int i = 0; i < city[curIndex].size(); i++)
	{
		//// 다리가 있는 경우
		//if (city[curIndex][i] != 0)
		//{
		//	_path(i, min(curCost, city[curIndex][i]));

		//}
		_path(city[curIndex][i].first, min(curCost, city[curIndex][i].second));
	}

}
*/

void pathBinary()
{
	int left = 1;
	int right = MAXCost;
	while (1)
	{
		if (left > right)break;
		memset(visited, false, sizeof(visited));
		int mid = (left + right) / 2;
		if (_path(mid) == 1)
		{
			result = max(result, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
}

int _path(int curCost)
{
	queue<int> path;
	visited[startCity] = true;
	path.push(startCity);
	while (1)
	{
		if (path.size() == 0)break;
		int top = path.front();
		path.pop();

		if (top == endCity)return 1;
		for (int i = 0; i < city[top].size(); i++)
		{
			int nextindex = city[top][i].first;
			int nextCost = city[top][i].second;
			// 지금 가중치로 갈수 있는 case
			if (visited[nextindex] == false && curCost <= nextCost)
			{
				path.push(nextindex);
				visited[nextindex] = true;
			}
		}
	}
	return 0;
}


