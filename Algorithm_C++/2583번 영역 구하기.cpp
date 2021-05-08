#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
vector<vector<int>> map;
vector<vector<bool>> visited;
int _count;
vector<int> result;
void DFS(int curX, int curY);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> M >> N >> K;
	map = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));
	visited = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false));
	for (int i = 0; i < K; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int _x1 = M - y1;
		int _y1 = x1;
		int _x2 = M - y2;
		int _y2 = x2;
		if (_x1 > _x2)
		{
			for (int j = _x2; j < _x1; j++)
			{
				if (_y1 > _y2)
				{
					for (int z = _y2; z < _y1; z++)
					{
						map[j][z] = 1;
					}
				}
				else
				{
					for (int z = _y1; z < _y2; z++)
					{
						map[j][z] = 1;
					}
				}
			}
		}
		else
		{
			for (int j = _x1; j < _x2; j++)
			{
				if (_y1 > _y2)
				{
					for (int z = _y2; z < _y1; z++)
					{
						map[j][z] = 1;
					}
				}
				else
				{
					for (int z = _y1; z < _y2; z++)
					{
						map[j][z] = 1;
					}
				}
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 && visited[i][j] == false)
			{
				_count = 0;
				DFS(i, j);
				result.push_back(_count);
			}
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size() - 1; i++)
	{
		cout << result[i] << " ";
	}
	cout << result[result.size() - 1] << "\n";
	return 0;
}

void DFS(int curX, int curY)
{
	if (curX < 0 || curY < 0 || curX >= M || curY >= N) return;
	if (visited[curX][curY] == true)return;

	visited[curX][curY] = true;
	if (map[curX][curY] == 1)return;
	else
	{
		_count++;
		DFS(curX - 1, curY);
		DFS(curX + 1, curY);
		DFS(curX, curY - 1);
		DFS(curX, curY + 1);
	}
}
