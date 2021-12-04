#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N, M;
int result;
bool chk;
vector<vector<int>> student;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	student = vector<vector<int>>(N + 1, vector<int>(N+1,0));
	for (int i = 0; i < M; i++)
	{
		int small, big;
		cin >> small >> big;
	
		student[small][big] = 1;
		student[big][small] = -1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int z = 1; z <= N; z++)
			{
				if (student[j][z] == 0)
				{
					if (student[j][i] == 1 && student[i][z] == 1)student[j][z] = 1;
					if (student[j][i] == -1 && student[i][z] == -1)student[j][z] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		chk = false;
		for (int j = 1; j<= N; j++)
		{
			if (i == j)continue;
			else if (student[i][j] == 0)
			{
				chk = true;
				break;
			}
		}
		if (!chk) result++;
	}
	cout << result << "\n";
	return 0;
}