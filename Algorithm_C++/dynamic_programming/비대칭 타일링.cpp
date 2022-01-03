#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

long long int number = 1000000007;
int n;

// 전체 타일갯수
vector<long long int> TILING;
// 대칭인 타일개수
//vector<long long int> symmetry;

// 전체 타일갯수에서 대칭인 타일개수 뺀 값.(=비대칭인 타일갯수)
long long int result;
void countTILING(int curindex);
//void SYM(int curindex);
void solve(int curindex);
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		TILING.clear();
		//symmetry.clear();
		TILING.push_back(1);
		TILING.push_back(2);
		//symmetry.push_back(1);
		//symmetry.push_back(2);
		if (n > 2)
		{
			// 전체 타일링방법 갯수
			countTILING(2);
			// 대칭인 타일링방법 갯수를 뺀 경우.
			//SYM(2);
			solve(n);
		}
		//cout << TILING[n - 1] - symmetry[n - 1] << "\n";
		if (n > 2)
		{
			cout << result << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}



	return 0;
}

void countTILING(int curindex)
{
	if (curindex == n)return;
	long long int count = (TILING[curindex - 1] + TILING[curindex - 2]) % number;
	TILING.push_back(count);

	return countTILING(curindex + 1);
}

void solve(int n)
{
	// 홀수 인경우
	if (n % 2 == 1)
	{
		result = (TILING[n - 1] - TILING[(n - 1) / 2] + number) % number;
		return;
	}
	else
	{
		result = TILING[n - 1];
		result = (result - TILING[(n - 1) / 2] + number) % number;
		result = (result - TILING[(n - 1) / 2 - 1] + number) % number;
		return;
	}
}


/*
void SYM(int curindex)
{
	// 홀수 이면.... 가운데가 세로하나짜리여야 대칭.
	// 짝수 이면 가운데 두개가 가로로 된것 두개 or 좌우가 완전 똑같은 경우.
	if (curindex == n)return;
	// 짝수 일경우
	if (curindex % 2 == 1)
	{
		int evencount;
		evencount = (TILING[curindex / 2] % number); // 좌우가 완전이 똑같으려면 TILING[n/2] 이거랑 같아야함
		evencount = (TILING[curindex / 2 - 1] % number); // 가운데 두개가 가로로 된것.
		symmetry.push_back(evencount);
	}
	// 홀수 일경우
	else
	{
		int oddnumber = 0;
		oddnumber = (TILING[curindex / 2 - 1] % number);
		symmetry.push_back(oddnumber);
	}
	return SYM(curindex + 1);
}
*/