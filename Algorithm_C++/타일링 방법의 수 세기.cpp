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
	// ���� index�� ����, ������ ���� ����.
	// �� �Ϳ��� | ��� �߰� --> square[curindex]+=square[curindex-1]
	// ���� �Ϳ��� = ��� �߰� --> square[curindex] += square[curindex-2]
	long long int count = (square[curindex - 1] + square[curindex - 2]) % number;
	square.push_back(count);
	return TILING(curindex + 1);
}
