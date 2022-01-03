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
	// ��ĭ���� �ʱ�ȭ .
	vector<vector<char>> star(N, vector<char>(N, ' '));

	// ��ǥ (0,0) ���� ����.
	setpattern(star, 0, 0, N);
	showstar(star, N);

	return 0;
}

void setpattern(vector<vector<char>>& star, int x, int y, int N)
{
	// N == 1 �̸� �� ä���.
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
			// ����� ���� �׳� ��ĭ���� ���ܵθ� �Ǵ� �׳� �Ѿ.
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
// ��� 
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
