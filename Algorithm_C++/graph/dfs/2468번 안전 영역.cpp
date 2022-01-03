#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> temp;
vector<vector<bool>> visited;
int maxHeight;
int result = 1;
void rain(int curX, int curY, int water);
int main()
{
	cin >> N;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int number;
			cin >> number;
			if (maxHeight < number)maxHeight = number;
			map[i][j] = number;
		}
	}
	visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
	for (int z = 1; z <= maxHeight; z++)
	{
		int _result = 0;
		visited = vector<vector<bool>>(N + 1, vector<bool>(N + 1, false));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] > z && !visited[i][j])
				{
					rain(i, j, z);
					_result++;
				}
			}
		}
		if (result < _result)result = _result;
	}
	cout << result << "\n";

	return 0;
}

void rain(int curX, int curY, int water)
{
	if (curX<1 || curY<1 || curX>N || curY>N)
	{
		return;
	}
	if (visited[curX][curY])return;
	visited[curX][curY] = true;
	if (map[curX][curY] <= water)return;
	else
	{
		rain(curX - 1, curY, water);
		rain(curX + 1, curY, water);
		rain(curX, curY - 1, water);
		rain(curX, curY + 1, water);
	}
}
