#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int N;
int gameboard[101][101];
long long pathcount[101][101];
//bool path(int cur_x, int cur_y,long long& count);
long long path(int cur_x, int cur_y);

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			pathcount[i][j] = -1;
			int number;
			cin >> number;
			gameboard[i][j] = number;
		}
	}
	long long result = 0;
	result += path(0, 0);
	cout << result << "\n";
	return 0;
}


long long path(int cur_x, int cur_y)
{
	if (cur_x >= N || cur_y >= N)return 0;
	if (cur_x == N - 1 && cur_y == N - 1)return 1;
	int jump = gameboard[cur_y][cur_x];
	// �������� �ƴѵ� �� �� �ִ� ����� 0�ΰ��.
	if (cur_x < N && cur_y < N)
	{
		if (jump == 0)return 0;
	}

	long long& count = pathcount[cur_y][cur_x];
	if (count != -1)return count;

	count = (path(cur_x + jump, cur_y)) + (path(cur_x, cur_y + jump));
	return count;
}

















// �ð��ʰ���.
/*
int main()
{
	cin >> N;
	long long count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			gameboard[i][j] = number;
		}
	}
	path(0, 0, count);
	cout << count << "\n";
	return 0;
}

bool path(int cur_x, int cur_y,long long& count)
{
	// ���� �Ѿ�� ���
	if (cur_x >= N || cur_y >= N)return false;
	// ������ ���
	if (cur_x == N - 1 && cur_y == N - 1)
	{
		count++;
		return true;
	}
	int jump = gameboard[cur_y][cur_x];
	// ���������� �̵�
	path(cur_x + jump, cur_y, count);

	// �Ʒ��� �̵�
	path(cur_x, cur_y + jump, count);
	return false;
}
*/


