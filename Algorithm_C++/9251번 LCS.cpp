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
		// -1�� �ʱ�ȭ �ϴ� ����...
		// ���� dp[leftsize-1][rightsize-1]�� Ȯ���Ҷ�
		// ��ĭ �� �̵��ϸ� 0�� ���ϵǾ� dp���� 0�� ���ٵ�
		// �ʱ�ȭ�� 0���� �س����� ���� �ᱹ �Ȱ���
		// �� ��츦 ������������ ������ ������ üũ�� �����ش�.
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
	// ���� ��� : ������ ���� ���� ��
	if (firstStrIndex >= leftsize || secondStrIndex >= rightsize)return 0;
	// ���� ��� : ���ĺ� �� ���� ��
	if (firstStr[firstStrIndex] == secondStr[secondStrIndex])
	{
		// �� ���ڿ��� �ε����� 1ĭ�� ���� �����ش�.
		// ���ĺ� ������ +1
		return LCS(firstStrIndex + 1, secondStrIndex + 1) + 1;
	}
	// ���� ��� : �̹� ������ �ε����ΰ��
	if (dp[firstStrIndex][secondStrIndex] != -1)return dp[firstStrIndex][secondStrIndex];

	// ������ʸ� �� ���� ���Ѱ���
	// �ϴ� ���ĺ��� Ʋ���ٴ°� --> ���ڿ� �ε����� �̵�
	// �ΰ��� ���ڿ��� �ϳ��� �����ؼ� ��ĭ�� �̵�
	// ��ĭ �� �̵������� �ΰ��� ����� ū ������ ����
	int temp = max(LCS(firstStrIndex + 1, secondStrIndex), LCS(firstStrIndex, secondStrIndex + 1));
	dp[firstStrIndex][secondStrIndex] = temp;
	return dp[firstStrIndex][secondStrIndex];
}
