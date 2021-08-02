#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
vector<vector<int>> adjFriend;
int result;
int checkAnswer = 987654321;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> M;

	adjFriend = vector<vector<int>>(N + 1, vector<int>(N + 1, 987654321));

	for (int i = 0; i < M; i++)
	{
		int friendnum1, friendnum2;
		cin >> friendnum1 >> friendnum2;
		adjFriend[friendnum1][friendnum2] = 1;
		adjFriend[friendnum2][friendnum1] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int z = 1; z <= N; z++)
			{
				if (adjFriend[j][i] + adjFriend[i][z] < adjFriend[j][z])
				{
					adjFriend[j][z] = adjFriend[j][i] + adjFriend[i][z];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)continue;
			if (adjFriend[i][j] != 987654321)
			{
				temp += adjFriend[i][j];
			}
		}
		if (checkAnswer > temp)
		{
			checkAnswer = temp;
			result = i;
		}
	}
	cout << result << "\n";

	return 0;
}