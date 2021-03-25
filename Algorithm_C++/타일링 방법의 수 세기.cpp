#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//long long int count;
int n;
void TILING(int curindex);
vector<long long int> square;
long long int number = 1000000007;
int main()
{
	int c;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		cin >> n;
		square.clear();
		square.push_back(1);
		square.push_back(2);
		if (n >= 3)
		{
			TILING(2);
		}
		cout << square[n - 1] % number << "\n";
	}


	return 0;
}

void TILING(int curindex)
{
	if (curindex == n)return;
	// 현재 index는 전것, 전전것 에서 가능.
	// 전 것에서 | 모양 추가 --> square[curindex]+=square[curindex-1]
	// 전전 것에서 = 모양 추가 --> square[curindex] += square[curindex-2]
	long long int count = (square[curindex - 1] + square[curindex - 2]) % number;
	square.push_back(count);
	return TILING(curindex + 1);
}
