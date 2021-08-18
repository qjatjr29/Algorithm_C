#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> universe;
vector<bool> visited;
int result = 987654321;
// �� �������� ���� �ִ� �Ÿ��� ���ϴ� �Լ�
void calcMinTime();
// ��� �༺ Ž�� ����
void startExploration(vector<bool> temp, int movingTime, int curIndex, int planetCount);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> K;
	universe = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	visited = vector<bool>(N + 1, false);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int moveTime;
			cin >> moveTime;
			universe[i][j] = moveTime;
		}
	}

	calcMinTime();
	cout << result << "\n";


	return 0;
}

void calcMinTime()
{
	// �߰��� �� ����
	for (int i = 0; i < N; i++)
	{
		// j = ���
		for (int j = 0; j < N; j++)
		{
			// z = ����
			for (int z = 0; z < N; z++)
			{
				if (universe[j][i] + universe[i][z] < universe[j][z])
				{
					universe[j][z] = universe[j][i] + universe[i][z];
				}
			}
		}
	}
	//int result = 0;
	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		cout << universe[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << result << "\n";
	visited[K] = true;
	startExploration(visited, 0, K, 1);
}

void startExploration(vector<bool> temp, int movingTime, int curIndex, int planetCount)
{
	/*
	// ���� ���� �湮�� �༺ ��
	// ��������� �̵��� �༺ �Ÿ�
	// ���� index
	priority_queue<pair<int,pair<int, int>>> pq;

	pq.push(make_pair(1, make_pair(0, K)));
	visited[K] = true;

	while (1)
	{
		if (pq.empty())break;
		int visitedPlanet = pq.top().first;
		int movingLength = -pq.top().second.first;
		int curIndex = pq.top().second.second;

		if (visitedPlanet == N)
		{
			result = movingLength;
			break;
		}

		int nextIndex = 0;
		int temp = 987654321;
		for (int i = 0; i < N; i++)
		{
			if (i == curIndex)continue;
			if (temp > universe[curIndex][i] && visited[i] == false)
			{
				temp = universe[curIndex][i];
				nextIndex = i;
			}
		}
		pq.push(make_pair(visitedPlanet + 1, make_pair(-(movingLength + temp), nextIndex)));
		visited[nextIndex] = true;

	}
	*/

	if (planetCount == N)
	{
		result = min(result, movingTime);
		return;
	}



	for (int i = 0; i < N; i++)
	{
		if (i == curIndex)continue;
		if (temp[i] == false)
		{
			temp[i] = true;
			startExploration(temp, movingTime + universe[curIndex][i], i, planetCount + 1);
			temp[i] = false;
		}
	}






}
