#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> computer;
int FindComputer(int start, int count);
vector<bool> visited;
vector<vector<int>> result;
int resultNumber;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;

	computer = vector<vector<int>>(N + 1, vector<int>());
	result = vector<vector<int>>(N + 1, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int com1, com2;
		cin >> com1 >> com2;
		computer[com2].push_back(com1);
	}
	for (int i = 1; i <= N; i++)
	{
		if (computer[i].size() > 0)
		{
			visited = vector<bool>(N + 1, false);
			int _count = FindComputer(i, 1);
			if (resultNumber < _count)
			{
				resultNumber = _count;
			}
			result[_count].push_back(i);
		}
	}
	for (int i = 0; i < result[resultNumber].size() - 1; i++)
	{
		cout << result[resultNumber][i] << " ";
	}
	cout << result[resultNumber][result[resultNumber].size() - 1] << "\n";
	return 0;
}

int FindComputer(int start, int count)
{
	queue<int> pq;
	/*pq.push(start);*/
	visited[start] = true;
	for (int i = 0; i < computer[start].size(); i++)
	{
		if (visited[computer[start][i]] == false)
		{
			visited[computer[start][i]] = true;
			pq.push(computer[start][i]);
			count++;
		}
	}

	while (1)
	{
		if (pq.empty())break;
		int curIndex = pq.front();
		pq.pop();
		for (int i = 0; i < computer[curIndex].size(); i++)
		{
			if (visited[computer[curIndex][i]] == false)
			{
				visited[computer[curIndex][i]] = true;
				pq.push(computer[curIndex][i]);
				count++;
			}
		}
	}
	return count;
}
