#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int n; // 우물의 깊이
int m; // 장마 기간 길이
double probability;
double cache[1001][2002];
double snail(int height, int day);


int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n >> m;
		for (int j = 0; j < m; j++)
		{
			for (int z = 0; z < n; z++)
			{
				cache[j][z] = -1;
			}
		}
		probability = snail(0, 0);
		cout << setprecision(10) << fixed << probability << "\n";
	}


	return 0;
}

double snail(int height, int day)
{
	if (height >= n) return 1;
	if (day == m)
	{
		if (height >= n)return 1;
		else return 0;
	}

	double& temp = cache[day][height];
	if (temp != -1)
	{
		return temp;
	}

	return temp = 0.75 * (snail(height + 2, day + 1)) + 0.25 * (snail(height + 1, day + 1));

}
