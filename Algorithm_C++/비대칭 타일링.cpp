#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

long long int number = 1000000007;
int n;

// ��ü Ÿ�ϰ���
vector<long long int> TILING;
// ��Ī�� Ÿ�ϰ���
//vector<long long int> symmetry;

// ��ü Ÿ�ϰ������� ��Ī�� Ÿ�ϰ��� �� ��.(=���Ī�� Ÿ�ϰ���)
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
			// ��ü Ÿ�ϸ���� ����
			countTILING(2);
			// ��Ī�� Ÿ�ϸ���� ������ �� ���.
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
	// Ȧ�� �ΰ��
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
	// Ȧ�� �̸�.... ����� �����ϳ�¥������ ��Ī.
	// ¦�� �̸� ��� �ΰ��� ���η� �Ȱ� �ΰ� or �¿찡 ���� �Ȱ��� ���.
	if (curindex == n)return;
	// ¦�� �ϰ��
	if (curindex % 2 == 1)
	{
		int evencount;
		evencount = (TILING[curindex / 2] % number); // �¿찡 ������ �Ȱ������� TILING[n/2] �̰Ŷ� ���ƾ���
		evencount = (TILING[curindex / 2 - 1] % number); // ��� �ΰ��� ���η� �Ȱ�.
		symmetry.push_back(evencount);
	}
	// Ȧ�� �ϰ��
	else
	{
		int oddnumber = 0;
		oddnumber = (TILING[curindex / 2 - 1] % number);
		symmetry.push_back(oddnumber);
	}
	return SYM(curindex + 1);
}
*/