#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;


vector<vector<int>> map;
vector<vector<bool>> checkPostion;
int paperArray[5] = { 5,5,5,5,5 };
int result = 987654321;
int cnt;
void colorPaper(int x, int y);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	map = vector<vector<int>>(11, vector<int>(11, 0));
	checkPostion = vector<vector<bool>>(11, vector<bool>(11, false));
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			int state;
			cin >> state;
			map[i][j] = state;

		}
	}
	colorPaper(1, 1);

	if (result == 987654321)
	{
		cout << -1 << "\n";
	}
	else cout << result << "\n";


	return 0;
}



void colorPaper(int x, int y)
{
	if (y == 11)
	{
		colorPaper(x + 1, 1);
		return;
	}
	if (x == 11)
	{
		result = min(result, cnt);
		return;
	}
	if (map[x][y] == 0)
	{
		colorPaper(x, y + 1);
		return;
	}

	// 5가지 정사각형 확인.
	for (int i = 5; i >= 1; i--)
	{
		if (paperArray[i - 1] == 0 || x + i > 11 || y + i > 11)continue;
		bool establishment = true;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				if (map[x + j][y + k] == 0)
				{
					establishment = false;
					break;
				}
			}
			if (!establishment)break;
		}
		if (!establishment)continue;
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				map[x + j][y + k] = 0;
			}
		}
		paperArray[i - 1]--;
		cnt++;
		colorPaper(x, y + i);
		for (int j = 0; j < i; j++)
		{
			for (int k = 0; k < i; k++)
			{
				map[x + j][y + k] = 1;
			}
		}
		paperArray[i - 1]++;
		cnt--;
	}

}
