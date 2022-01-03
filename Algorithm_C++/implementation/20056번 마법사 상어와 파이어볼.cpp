#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, K;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

// N*N 칸 중에 파이어볼이 있는 칸 체크  2개이상인지 확인하려고
vector<vector<int>> map;
// (r,c)  /  m  / (s,d)
queue<pair<pair<int, int>, pair<int, pair<int, int>>>> fireball;
vector<vector<vector<pair<int, pair<int, int>>>>> temp;
void moveFireball();
void checkFireball();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M >> K;

	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireball.push(make_pair(make_pair(r, c), make_pair(m, make_pair(s, d))));
	}

	for (int i = 0; i < K; i++)
	{
		moveFireball();
		checkFireball();
	}
	int result = 0;
	while (1)
	{
		if (fireball.empty())break;
		result += fireball.front().second.first;
		fireball.pop();
	}
	cout << result << "\n";

	return 0;
}

void moveFireball()
{

	int size = fireball.size();
	temp = vector<vector<vector<pair<int, pair<int, int>>>>>(N + 1, vector<vector<pair<int, pair<int, int>>>>(N + 1, vector<pair<int, pair<int, int>>>()));



	for (int i = 0; i < size; i++)
	{
		int curX = fireball.front().first.first;
		int curY = fireball.front().first.second;
		int weight = fireball.front().second.first;
		int speed = fireball.front().second.second.first;
		int direction = fireball.front().second.second.second;

		fireball.pop();

		for (int j = 0; j < speed; j++)
		{
			curX += dx[direction];
			curY += dy[direction];
			if (curX <= 0)
			{
				curX = N + curX;
			}
			else if (curX > N)
			{
				curX = curX - N;
			}
			if (curY <= 0)
			{
				curY = N + curY;
			}
			else if (curY > N)
			{
				curY = curY - N;
			}
		}
		//map[curX][curY]++;

		temp[curX][curY].push_back(make_pair(weight, make_pair(speed, direction)));


	}

}

void checkFireball()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			// 한 칸 안에 파이어볼이 하나인 경우
			if (temp[i][j].size() == 1)
			{
				int temp_weight = temp[i][j][0].first;
				int temp_speed = temp[i][j][0].second.first;
				int temp_direction = temp[i][j][0].second.second;
				fireball.push(make_pair(make_pair(i, j), make_pair(temp_weight, make_pair(temp_speed, temp_direction))));
			}
			// 한 칸 안에 파이어볼이 두개 이상인 경우
			else if (temp[i][j].size() >= 2)
			{
				int temp_weight = 0;
				int temp_speed = 0;
				bool temp_direction = true;
				int check_direction = temp[i][j][0].second.second % 2;
				for (int z = 0; z < temp[i][j].size(); z++)
				{
					temp_weight += temp[i][j][z].first;

					if (temp[i][j][z].second.second % 2 != check_direction)
					{
						temp_direction = false;
					}
					temp_speed += temp[i][j][z].second.first;
				}
				temp_weight = temp_weight / 5;
				temp_speed = temp_speed / temp[i][j].size();
				if (temp_weight != 0)
				{
					// 0 2 4 6 방향 으로 4개 생성
					if (temp_direction)
					{
						for (int k = 0; k < 7; k += 2)
						{
							fireball.push(make_pair(make_pair(i, j), make_pair(temp_weight, make_pair(temp_speed, k))));
						}

					}
					// 1 3 5 7 방향으로 4개 생성
					else
					{
						for (int k = 1; k <= 7; k += 2)
						{
							fireball.push(make_pair(make_pair(i, j), make_pair(temp_weight, make_pair(temp_speed, k))));
						}
					}
				}

			}
		}
	}
}
