#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int result;
vector<int> preNode;
vector < pair<int, pair<int, int>>> road;
int getPreNode(int index);
bool cycleChk(int idx1, int idx2);
void city();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	preNode = vector<int>(N + 1, 0);
	for (int i = 0; i < M; i++)
	{
		int sh, dh, cost;
		cin >> sh >> dh >> cost;
		road.push_back(make_pair(cost, make_pair(sh, dh)));
	}
	sort(road.begin(), road.end());
	for (int i = 1; i <= N; i++)
	{
		preNode[i] = i;
	}
	city();
	cout << result << "\n";


	return 0;
}

int getPreNode(int index)
{
	if (preNode[index] == index)return index;
	return getPreNode(preNode[index]);
}

bool cycleChk(int idx1, int idx2)
{
	int rtn = getPreNode(idx1);
	int rtn2 = getPreNode(idx2);
	if (rtn == rtn2)return false;
	return true;
}

void city()
{
	int lastNum;
	for (int i = 0; i < M; i++)
	{
		int rtn = getPreNode(road[i].second.first);
		int rtn2 = getPreNode(road[i].second.second);
		if (rtn == rtn2)continue;
		result += road[i].first;
		lastNum = road[i].first;
		if (rtn > rtn2)
		{
			preNode[rtn] = rtn2;
		}
		else preNode[rtn2] = rtn;
	}
	result -= lastNum;
}
