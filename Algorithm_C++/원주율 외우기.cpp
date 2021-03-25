#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321;
string number;
int level;
int pi(int curindex);
int levelcheck(int curindex, int addnumber);
int checkarr[10002];
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		// 배열 초기화
		memset(checkarr, -1, sizeof(checkarr));
		cin >> number;
		cout << pi(0) << "\n";
	}

	return 0;
}

int pi(int curindex)
{
	// 범위를 넘어 갔을때 (딱 끝나서)
	if (curindex == number.size())return 0;

	//int temp = checkarr[curindex];
	if (checkarr[curindex] != -1) return checkarr[curindex];

	// 3 - 나머지 / 4 - 나머지 / 5- 나머지
	// 3,4,5,로 나눴을때 나눈 경우의 난이도 + 나머지 부분의 난이도 를 구해서 최솟값으로
	checkarr[curindex] = INF;
	for (int i = 3; i <= 5; i++)
	{
		// 범위 안넘어갈때.
		if (curindex + i <= number.size())
		{
			checkarr[curindex] = min(checkarr[curindex], levelcheck(curindex, curindex + i - 1) + pi(curindex + i));
		}
	}

	return checkarr[curindex];
}


int levelcheck(int curindex, int addnumber)
{
	string _number = number.substr(curindex, addnumber - curindex + 1);

	int size = _number.size();

	// 모두 같은 수인지 체크
	bool same = true;
	for (int i = 0; i < size - 1; i++)
	{
		if (_number[i] != _number[i + 1])
		{
			same = false;
			break;
		}
	}
	if (same)return 1;

	// 등차수열인지 확인
	bool progression = true;
	for (int i = 0; i < size - 1; i++)
	{
		if (_number[i] - _number[i + 1] != _number[0] - _number[1])
		{
			progression = false;
			break;
		}
	}
	if (progression)
	{
		// 1씩 단조 증가, 단조 감소
		if (abs(_number[0] - _number[1]) == 1)
		{
			return 2;
		}
		// 등차수열 이룰때.
		else return 5;
	}

	// 번갈아 출현할때.
	bool check = true;
	for (int i = 0; i < size; i++)
	{
		if (_number[i] != _number[i % 2])
		{
			check = false;
			break;
		}
	}
	if (check)return 4;

	// 그외 경우
	return 10;
}
