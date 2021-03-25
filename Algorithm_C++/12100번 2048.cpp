#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<int> map[21];
int move[4] = { -1,1,-1,1 };
int result;
int blockNum;
void moveBlock(pair<int, int> store, int blockCount);
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int block;
			cin >> block;
			if (block != 0)
			{
				blockNum++;
				if (result < block)result = block;
			}
			map[i].push_back(block);
		}
	}

	pair<int, int> store;

	// 0번 움직였을 떄 가장 큰 블록 값.
	store = make_pair(result, 0);



	return 0;
}

void moveBlock(pair<int, int> store, int blockCount)
{
	int moveCount = store.second;
	int curMAX = store.first;

	// 최대 5번만 움직일 수 있다.
	if (moveCount == 5)return;

	// 블록이 하나라 이제 움직여도 최대값이 안늘어난다.
	if (blockCount == 1)return;

	for (int i = 0; i < 2; i++)
	{

	}

}
