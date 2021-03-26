#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
// map 저장
int map[1002][1002];
// 될 수 있는 정사각형 길이 저장 
int square[1002][1002];
int Maxlength;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> n >> m;

	// 초기화 작업.
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; j++)
		{
			int number = a[j] - '0';
			if (number == 1)
			{
				square[i][j] = 1;
				map[i][j] = 1;
			}
		}
	}

	// 범위가 2x2 이상일 때.
	if (n > 1 && m > 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				// 자기가 1일 때만 주변이 정사각형이 되는지 확인 
				if (map[i][j] == 1)
				{
					// 주변이 하나라도 1이 아니면 정사각형이 될 수 없다.
					// 0 이 하나라도 존재
					if (square[i - 1][j] != 0 && square[i][j - 1] != 0 && square[i - 1][j - 1] != 0) {
						if (square[i - 1][j] != 1 && square[i][j - 1] != 1 && square[i - 1][j - 1] != 1)
						{
							// 주변 3개 값중에 가장 작은 값 +1 이 
							// 정사각형이 될 수 있는 길이
							int w = min(square[i - 1][j], square[i][j - 1]);
							w = min(w, square[i - 1][j - 1]);
							square[i][j] = w + 1;
						}
						else
						{
							// 하나라도 값이 1이면 이걸 포함한 정사각형의
							// 최대길이는 2임.
							square[i][j] = 2;
						}
					}
				}

				// 반복문 돌면서 최대 길이 값을 구한다.
				Maxlength = max(Maxlength, square[i][j]);
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (Maxlength == 1)break;
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					Maxlength = 1;
					break;
				}
			}
		}

	}

	// 넓이 구하는건 길이 * 길이
	cout << pow(Maxlength, 2) << "\n";

	return 0;
}