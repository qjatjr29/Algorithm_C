#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int result;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N >> M;

	// n�� 3�̻� m�� 7�̻��϶� 4���� ��� �� ���ƾ��Ѵ�.
	if (N == 1)
	{
		result = 1;
	}
	else if (N == 2)
	{
		result = min(4, (M - 1) / 2 + 1);
	}
	else
	{
		// ������ 4���� ��� �� ������.==> 4�� �ִ�
		// 1, 4 ��° ���� ���°� �ִ�.
		if (M < 7)
		{
			result = min(4, M);
		}
		// 2, 3 ��°�� ���� ��� �ΰ����� �� �ڷδ� �� 1,4,�����θ� �̵��ؼ� �ִ븦 �����.
		// 2 : (2,3���� �̵��ϴ� ���)
		// m-5 : ���� m���� �̵��� �Ÿ� 5ĭ ����(ó���ִ��� + 2,3���� �̵� 4ĭ)
		// 1 : ���� �ִ� ��.
		else
		{
			result = 2 + M - 5 + 1;
		}
	}
	cout << result << "\n";
	return 0;
}













