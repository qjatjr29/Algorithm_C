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
		// �迭 �ʱ�ȭ
		memset(checkarr, -1, sizeof(checkarr));
		cin >> number;
		cout << pi(0) << "\n";
	}

	return 0;
}

int pi(int curindex)
{
	// ������ �Ѿ� ������ (�� ������)
	if (curindex == number.size())return 0;

	//int temp = checkarr[curindex];
	if (checkarr[curindex] != -1) return checkarr[curindex];

	// 3 - ������ / 4 - ������ / 5- ������
	// 3,4,5,�� �������� ���� ����� ���̵� + ������ �κ��� ���̵� �� ���ؼ� �ּڰ�����
	checkarr[curindex] = INF;
	for (int i = 3; i <= 5; i++)
	{
		// ���� �ȳѾ��.
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

	// ��� ���� ������ üũ
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

	// ������������ Ȯ��
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
		// 1�� ���� ����, ���� ����
		if (abs(_number[0] - _number[1]) == 1)
		{
			return 2;
		}
		// �������� �̷궧.
		else return 5;
	}

	// ������ �����Ҷ�.
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

	// �׿� ���
	return 10;
}
