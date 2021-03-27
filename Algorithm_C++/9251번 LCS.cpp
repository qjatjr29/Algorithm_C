#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


int dp[1001][1001];
int LCS(int x, int y);
string firstStr, secondStr;
int leftsize, rightsize;
int main()
{
	cin >> firstStr >> secondStr;

	leftsize = firstStr.size();
	rightsize = secondStr.size();

	for (int i = 0; i < leftsize; i++)
	{
		// -1로 초기화 하는 이유...
		// 만약 dp[leftsize-1][rightsize-1]을 확인할때
		// 한칸 씩 이동하면 0이 리턴되어 dp값이 0이 될텐데
		// 초기화를 0으로 해놓으면 값이 결국 똑같아
		// 이 경우를 지나갔음에도 지나간 것으로 체크를 못해준다.
		for (int j = 0; j < rightsize; j++)
		{
			dp[i][j] = -1;
		}
	}
	cout << LCS(0, 0) << "\n";





	return 0;
}

int LCS(int firstStrIndex, int secondStrIndex)
{
	// 기저 사례 : 범위를 벗어 났을 때
	if (firstStrIndex >= leftsize || secondStrIndex >= rightsize)return 0;
	// 기저 사례 : 알파벳 이 같을 때
	if (firstStr[firstStrIndex] == secondStr[secondStrIndex])
	{
		// 두 문자열의 인덱스를 1칸씩 증가 시켜준다.
		// 알파벳 같으니 +1
		return LCS(firstStrIndex + 1, secondStrIndex + 1) + 1;
	}
	// 기저 사례 : 이미 지나간 인덱스인경우
	if (dp[firstStrIndex][secondStrIndex] != -1)return dp[firstStrIndex][secondStrIndex];

	// 기저사례를 다 만족 안한경우면
	// 일단 알파벳이 틀리다는것 --> 문자열 인덱스를 이동
	// 두개의 문자열중 하나씩 선택해서 한칸씩 이동
	// 한칸 씩 이동시켰을 두가지 경우중 큰 값으로 선택
	int temp = max(LCS(firstStrIndex + 1, secondStrIndex), LCS(firstStrIndex, secondStrIndex + 1));
	dp[firstStrIndex][secondStrIndex] = temp;
	return dp[firstStrIndex][secondStrIndex];
}
