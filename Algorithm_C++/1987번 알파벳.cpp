#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int R, C;
vector<vector<char>> map;
vector<bool> visited;
int result;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void alpha(int startX, int startY, int count);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> R >> C;
	map = vector<vector<char>>(R + 1, vector<char>(C + 1, ' '));
	visited = vector<bool>(26, false);
	for (int i = 0; i < R; i++)
	{
		string word;
		cin >> word;
		for (int j = 0; j < word.size(); j++)
		{
			map[i][j] = word[j];
		}
	}
	visited[map[0][0] - '0' - 16] = true;
	alpha(0, 0, 1);
	if (result == 0)cout << 1 << "\n";
	else cout << result << "\n";
	return 0;
}

void alpha(int startX, int startY, int count)
{
	//방문
	visited[map[startX][startY] - '0' - 16] = true;
	for (int i = 0; i < 4; i++)
	{
		int moveX = startX + dx[i];
		int moveY = startY + dy[i];
		if (moveX >= 0 && moveX < R && moveY >= 0 && moveY < C)
		{
			if (visited[map[moveX][moveY] - '0' - 16])continue;
			result = max(result, count + 1);
			alpha(moveX, moveY, count + 1);
		}
	}
	// 초기화
	visited[map[startX][startY] - '0' - 16] = false;

	//queue<pair<pair<int,int>, int>> q;
	//q.push(make_pair(make_pair(startX,startY), 1));
	//while (1)
	//{
	//	if (q.empty())break;
	//	int curX = q.front().first.first;
	//	int curY = q.front().first.second;
	//	int curCount = q.front().second;
	//	q.pop();
	//	// 4가지 방향으로 갈 수 있는지 아닌지 확인
	//	bool check = false;
	//	visited[map[curX][curY] - '0' - 16] = true;
	//	for (int i = 0; i < 4; i++)
	//	{
	//		int moveX = curX + dx[i];
	//		int moveY = curY + dy[i];
	//		if (moveX >= 0 && moveX < R && moveY >= 0 && moveY < C)
	//		{
	//			if (visited[map[moveX][moveY] - '0' - 16])continue;
	//			else
	//			{
	//				q.push(make_pair(make_pair(moveX, moveY), curCount + 1));
	//				check = true;
	//			}
	//		}
	//	}
	//	if (check == false)
	//	{
	//		result = max(result, curCount);
	//		//visited[map[curX][curY] - '0' - 16] = false;
	//	}
	//}
}
