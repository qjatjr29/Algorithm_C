#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N;
vector<int> oil;
vector<int> road;
long long  result;

void oilCost(int curindex);
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N;
	oil = vector<int>(N + 1, 0);
	road = vector<int>(N + 1, 0);

	for (int i = 1; i < N; i++)
	{
		// road[i] ==> i���� i+1�� ���� ������ ����.
		int roadNum;
		cin >> roadNum;
		road[i] = roadNum;
	}
	for (int i = 1; i <= N; i++)
	{
		// oil[i] ==> i��° ���ÿ����� 1L�� �⸧ ����
		int oilNum;
		cin >> oilNum;
		oil[i] = oilNum;
	}
	oilCost(1);

	cout << result << "\n";
	return 0;
}

void oilCost(int curindex)
{
	//���� ���
	if (curindex == N)return;

	// ���� ��ġ�� 1L�� ����
	long long curindexCost = oil[curindex];

	// ���� ��ġ���� �̵��� �Ÿ�
	int move = 0;

	// �󸶳� ���� ���ø� �̵��ߴ��� Ȯ���ϴ� ����
	int count = 0;

	// ���� ��ġ���� ���� �������� ������ ���� ���� ���� �� ���� �̵�
	// ������ ��ĭ�� �������� �ϴ� i =curindex ���� ����
	for (int i = curindex; i < N; i++)
	{
		long long temp = 0;
		// ������ ������ ���ݺ��� ���� �� ����� �Ѿ��.
		if (curindexCost > oil[i])
		{
			break;
		}
		count++;  // ��ĭ�� ������ ������ ++
		move += road[i];	 // ��ĭ ������ �� �̵� �Ÿ� + ���ֱ�
	}

	result += curindexCost * move;

	//check[curindex] = curMinCost;
	oilCost(curindex + count);
	return;
}
