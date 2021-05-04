#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int M, N, K;
vector<vector<int>> map;
vector<vector<bool>> visited;
int result;
void sol(int curX, int curY);
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		result = 0;
		map = vector<vector<int>>(M + 1, vector<int>(N + 1, 0));
		visited = vector<vector<bool>>(M + 1, vector<bool>(N + 1, false));
		for (int j = 0; j < K; j++)
		{
			int row, col;
			cin >> row >> col;
			map[row][col] = 1;
		}
		for (int j = 0; j < M; j++)
		{
			for (int z = 0; z < N; z++)
			{
				if (map[j][z] == 1)
				{
					result++;
					sol(j, z);
				}
			}
		}
		cout << result << "\n";
	}

	return 0;
}

void sol(int curX, int curY)
{
	if (curX < 0 || curY < 0 || curX >= M || curY >= N)return;
	if (visited[curX][curY] == true)return;

	visited[curX][curY] = true;
	if (map[curX][curY] != 1)return;
	else map[curX][curY] = 2;
	sol(curX - 1, curY);
	sol(curX + 1, curY);
	sol(curX, curY - 1);
	sol(curX, curY + 1);
}
