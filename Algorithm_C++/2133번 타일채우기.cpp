#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;
vector<int> Tile;
int main()
{
	cin >> N;
	Tile = vector<int>(N + 1, 0);
	Tile[2] = 3;

	//짝수일떄만 가능
	// 4이상 일때 부터 점화식
	for (int i = 4; i < N + 1; i += 2)
	{
		// 저번 케이스 * 3 
		Tile[i] = Tile[i - 2] * 3;
		// 이상하게 생긴 모양 4칸 이상 부터 가능
		// 4칸 이상이면 이상하게 생긴 모양은 무조건 2개
		// 4칸 뺏을 때 남은 칸으로 만들수 있는 모양 수 * 2 해주면 될듯.
		for (int j = 2; j <= i - 4; j += 2)
		{
			Tile[i] += Tile[j] * 2;
		}
		// i는 4이상이니깐 자기도 이상한 모양 하나 가능.
		Tile[i] += 2;
	}

	cout << Tile[N] << "\n";
	return 0;
}