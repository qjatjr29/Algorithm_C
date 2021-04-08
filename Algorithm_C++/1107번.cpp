#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int N, M;
bool check[10];
int startHundred;
int BtnCount = 987654321;

// 숫자버튼만 이용해서 이동할 수 있는 경우. return 참, 거짓
bool Btn(int curNumber);

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int number;
		cin >> number;
		check[number] = true;
	}
	startHundred = abs(N - 100);
	for (int i = 0; i < 1000001; i++)
	{
		// 누를수 있는 숫자가 나왔을때
		if (Btn(i))
		{
			// 누를수 있는 숫자에서  + - 로 가는 경우.
			int count = abs(N - i);
			int iCount = 0;
			int temp = i;
			if (temp == 0)
			{
				iCount = 1;

			}
			while (1)
			{
				if (temp <= 0)break;
				temp /= 10;
				iCount++;
			}
			BtnCount = min(BtnCount, count + iCount);
		}
	}
	cout << min(BtnCount, startHundred) << "\n";
	return 0;
}

bool Btn(int curNumber)
{

	if (curNumber == 0)
	{
		if (check[0] == false)return true;
		else return false;
	}

	while (1)
	{
		if (curNumber <= 0)break;
		// 고장난 버튼의 번호가 포함되어 있는 경우
		if (check[curNumber % 10])return false;
		curNumber /= 10;
	}
	return true;
}