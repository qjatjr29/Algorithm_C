#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n;
int map[101][101];
bool check[101][101];

int jumpgame(int map[101][101], bool check[101][101], int x, int y, string& s);
int main()
{
	int C;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> n;
		string result = "NO";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				check[i][j] = 0;
			}
		}
		jumpgame(map, check, 0, 0, result);
		cout << result << "\n";
	}



	return 0;
}

int jumpgame(int map[101][101], bool check[101][101], int x, int y, string& s)
{
	if (s == "YES")return 1;

	// 이미 왔던 곳이면 바로 나가기.
	if (check[x][y] == 1)
	{
		return 0;
	}
	// 끝에 도달했을때.
	if (x == n - 1 && y == n - 1)
	{
		return 1;
	}
	// 범위 넘어간 경우
	if (x > n - 1 || y > n - 1)
	{
		return 0;
	}

	// 움직이는 값.
	int jump = map[x][y];

	check[x][y] = true;

	// 오른쪽 또는 아래칸으로만 이동 가능.
	// 아래로 이동.
	if (jumpgame(map, check, x + jump, y, s))
	{
		s = "YES";
	}
	// 오른쪽으로 이동.
	if (jumpgame(map, check, x, y + jump, s))
	{
		s = "YES";
	}

}


