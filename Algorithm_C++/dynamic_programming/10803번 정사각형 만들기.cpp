#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int n, m;
int dp[101][10001];
int cutSquare(int row, int col);
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	cout << cutSquare(min(n, m), max(n, m)) << "\n";

	return 0;
}

// row < col
int cutSquare(int row, int col)
{
	if (row == col)return dp[row][col] = 1;
	if (row > col)return cutSquare(col, row);
	// 정사각형을 만들 수 있는 경우 바로 리턴
	if (col % row == 0) return col / row;

	int temp = dp[row][col];
	// dp에 값이 있는 경우
	if (temp != -1)return temp;

	temp = 987654321;

	int divide = col / row;

	// 긴변이 짧은 변의 2배 이상인경우
	// 한개 정사각형 없애고 다음으로 넘어간다.
	if (divide >= 3)
	{
		temp = min(temp, cutSquare(row, col - row) + 1);
	}

	else
	{
		// row 을 줄여가면서 구하기
		for (int i = 1; i <= row / 2; i++)
		{
			temp = min(temp, cutSquare(row - i, col) + cutSquare(i, col));
		}
		// col을 줄여가면서 구하기
		for (int i = 1; i <= col / 2; i++)
		{
			temp = min(temp, cutSquare(row, col - i) + cutSquare(row, i));
		}
	}
	dp[row][col] = temp;

	return temp;
}
