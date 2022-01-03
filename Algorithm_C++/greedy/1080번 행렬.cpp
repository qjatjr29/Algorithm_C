#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int metrix_a[51][51];
int metrix_b[51][51];
//bool same = true;
//bool checksame();
void reverse(int x, int y);
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string metrix;
		cin >> metrix;
		for (int j = 0; j < M; j++)
		{
			if (metrix[j] == '0')metrix_a[i][j] = 0;
			else metrix_a[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		string metrix;
		cin >> metrix;
		for (int j = 0; j < M; j++)
		{
			if (metrix[j] == '0')metrix_b[i][j] = 0;
			else metrix_b[i][j] = 1;
		}
	}
	int count = 0;
	bool check = false;

	if (N >= 3 && M >= 3)
	{
		for (int i = 0; i < N - 2; i++)
		{
			for (int j = 0; j < M - 2; j++)
			{
				if (metrix_a[i][j] != metrix_b[i][j])
				{
					reverse(j, i);
					count++;
				}
				bool same = true;
				for (int y = 0; y < N; y++)
				{
					for (int x = 0; x < M; x++)
					{
						if (metrix_a[y][x] != metrix_b[y][x])
						{
							same = false;
							break;
						}
					}
					if (same == false)break;
				}
				if (same == true)
				{
					check = true;
					break;
				}
			}
			if (check)break;
		}
	}
	else
	{
		check = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (metrix_a[i][j] != metrix_b[i][j])
				{
					check = false;
					break;
				}
			}
			if (check == false)break;
		}
	}
	if (check)cout << count << "\n";
	else cout << -1 << "\n";
	return 0;
}

/*
bool checksame()
{
	for (int i = 0; i < N; i++)
	{
		if (same == false)break;
		for (int j = 0; j < M; j++)
		{
			if (metrix_a[i][j] != metrix_b[i][j])
			{
				same = false;
				break;
			}
		}
	}
	return same;
}
*/

void reverse(int x, int y)
{
	for (int i = y; i < y + 3; i++)
	{
		for (int j = x; j < x + 3; j++)
		{
			if (metrix_a[i][j] == 0)metrix_a[i][j] = 1;
			else metrix_a[i][j] = 0;
		}
	}
}
