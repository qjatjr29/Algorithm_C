#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int K;
int W, H;
int horseMoveX[8] = { -1,-2,-2,-1,1,2,2,1 };
int horseMoveY[8] = { -2,-1,1,2,-2,-1,1,2 };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int result = -1;
bool checkVisit[202][202][32] = { false, };
vector<vector<int>> map;
void monkey();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> K;
	cin >> W >> H;
	map = vector<vector<int>>(H + 1, vector<int>(W + 1, 0));


	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int num;
			cin >> num;
			map[i][j] = num;
		}
	}
	monkey();

	cout << result << "\n";

	return 0;
}

void monkey()
{
	priority_queue <pair<pair<int, int>, pair<int, int>>> pq;
	pq.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
	checkVisit[0][0][0] = true;
	while (1)
	{

		if (pq.empty())break;
		int curMoveCnt = -pq.top().first.first;
		int curX = pq.top().second.first;
		int curY = pq.top().second.second;
		int curK = pq.top().first.second;
		//visited[curX][curY] = true;
		pq.pop();

		if (curX == H - 1 && curY == W - 1)
		{
			result = curMoveCnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nex = curX + dx[i];
			int ney = curY + dy[i];

			if (nex < 0 || nex >= H || ney < 0 || ney >= W)continue;
			if (map[nex][ney] == 1)continue;
			if (checkVisit[nex][ney][curK] == false)
			{
				pq.push(make_pair(make_pair(-(curMoveCnt + 1), curK), make_pair(nex, ney)));
				checkVisit[nex][ney][curK] = true;
			}
		}
		// 말처럼 갈 수 있는 경우.
		if (curK < K)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = curX + horseMoveX[i];
				int ny = curY + horseMoveY[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
				if (map[nx][ny] == 1)continue;
				if (checkVisit[nx][ny][curK + 1] == false)
				{
					pq.push(make_pair(make_pair(-(curMoveCnt + 1), curK + 1), make_pair(nx, ny)));
					checkVisit[nx][ny][curK + 1] = true;
				}
			}
		}
	}

}
