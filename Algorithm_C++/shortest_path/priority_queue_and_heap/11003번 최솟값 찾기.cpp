#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int N, L;
vector<int> A;
// �����ȿ� �ִ� ���� ���� ����
// ���� �տ� �ִ� ���� ���� ���� ��
// ������ ���� ���� �ִ� �ͺ��� ũ�� pop ���ָ鼭 �־��ֱ�.
deque<pair<int, int>> dq;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		// deque�� ũ��� �׻� L
		// i���� �� ���� �ּҰ� ã�ƾ��ϴ� ������ �޶�����.
		// i-L+1 <= ���� <= i
		// ���� ��� �� ����
		if (!dq.empty() && dq.front().second < i - L + 1)
		{
			dq.pop_front();
		}
		int number;
		cin >> number;
		// ������������ ������ �Ǿ�� �ϱ� ������.
		// ���� �Է¹��� ���ں��� deque �� ũ�Ⱑ ũ�ٸ� pop
		while (1)
		{
			if (dq.empty())break;
			// dq�� ���� �Է¹��� ������ ��
			if (dq.back().first <= number)break;
			dq.pop_back();
		}
		dq.push_back(make_pair(number, i));
		A.push_back(dq.front().first);
	}
	for (int i = 0; i < N - 1; i++)
	{
		cout << A[i] << " ";
	}
	cout << A[A.size() - 1] << "\n";
	return 0;
}
