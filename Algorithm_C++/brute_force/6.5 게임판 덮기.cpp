#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int H, W;

const int coverType[4][3][2] =
{
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};
// 책 참고함..
// 가장 왼쪽에 있는 흰블록 채우는 방법 4가지 그 블록의 왼쪽, 위는 채워져있을것.

int cover(vector<vector<int>>& map);
bool check(vector<vector<int>>& map, int x, int y, int z, int n);
int main()
{
	int C;
	cin >> C;

	for (int i = 0; i < C; i++)
	{

		cin >> H >> W;
		//int map[21][21];
		int whiteboard = 0;
		vector<vector<int>> map(H, vector<int>(W));

		for (int j = 0; j < H; j++)
		{
			string board;
			cin >> board;

			for (int z = 0; z < W; z++)
			{
				if (board[z] == '.')
				{
					whiteboard++;
					map[j][z] = 0;   // 흰색 = 0
				}
				else map[j][z] = 1;  // 검정 = 1
			}
		}
		if (whiteboard % 3 != 0)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << cover(map) << "\n";
		}

	}
	return 0;
}

int cover(vector<vector<int>>& map)
{
	int x = -1;
	int y = -1;
	int count = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 0) // 지금있는 배열에서 가장 왼쪽 위에 있는 흰색칸 찾기
			{
				x = j;
				y = i;
				break;
			}
		}
		if (x != -1)break;
	}
	if (y == -1)return 1; // 다 채운 경우

	for (int k = 0; k < 4; k++)
	{
		if (check(map, x, y, k, 1))
		{
			count += cover(map);
		}
		check(map, x, y, k, -1);
	}
	return count;

}
bool check(vector<vector<int>>& map, int x, int y, int z, int n)
{
	bool ok = true;
	int map_x;
	int map_y;
	for (int k = 0; k < 3; k++)
	{
		map_x = x + coverType[z][k][1];
		map_y = y + coverType[z][k][0];
		if (map_x < 0 || map_x >= map[0].size() || map_y < 0 || map_y >= map.size())
		{
			ok = false;
		}
		else if ((map[map_y][map_x] += n) > 1)
		{
			ok = false;
		}
	}
	return ok;
}
