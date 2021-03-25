#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void setpattern(vector<vector<char>>& star, int x, int y, int N);
void showstar(vector<vector<char>> star, int N);
int main()
{
	int N;
	cin >> N;
	// 빈칸으로 초기화 .
	vector<vector<char>> star(N, vector<char>(N, ' '));

	// 좌표 (0,0) 부터 시작.
	setpattern(star, 0, 0, N);
	showstar(star, N);

	return 0;
}

void setpattern(vector<vector<char>>& star, int x, int y, int N)
{
	// N == 1 이면 별 채우기.
	if (N == 1)
	{
		star[x][y] = '*';
		return;
	}
	int temp = N / 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// 가운데인 경우는 그냥 빈칸으로 남겨두면 되니 그냥 넘어감.
			if (i == 1 && j == 1)
			{
				continue;
			}
			else
			{
				// 0,0 -> 0,1 -> 0,2 -> 0,3
				// -> 1,0 -> 1,1 ...
				setpattern(star, x + (temp * i), y + (temp * j), temp);
			}
		}
	}
}
// 출력 
void showstar(vector<vector<char>> star, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << star[i][j];
		}
		cout << "\n";
	}
}
