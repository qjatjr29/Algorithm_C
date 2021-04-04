#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int result;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N >> M;

	// n이 3이상 m이 7이상일때 4가지 경우 다 돌아야한다.
	if (N == 1)
	{
		result = 1;
	}
	else if (N == 2)
	{
		result = min(4, (M - 1) / 2 + 1);
	}
	else
	{
		// 어차피 4가지 경우 다 못쓴다.==> 4가 최대
		// 1, 4 번째 경우로 가는게 최대.
		if (M < 7)
		{
			result = min(4, M);
		}
		// 2, 3 번째로 가는 경우 두가지와 그 뒤로는 다 1,4,번으로만 이동해서 최대를 만든다.
		// 2 : (2,3으로 이동하는 경우)
		// m-5 : 원래 m에서 이동한 거리 5칸 뺀다(처음있던곳 + 2,3으로 이동 4칸)
		// 1 : 원래 있던 곳.
		else
		{
			result = 2 + M - 5 + 1;
		}
	}
	cout << result << "\n";
	return 0;
}













