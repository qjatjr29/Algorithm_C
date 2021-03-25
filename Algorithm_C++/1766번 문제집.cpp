#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
priority_queue<int> problem;
vector<vector<int>> v;
vector<int> check;
int main()
{
	cin >> N >> M;
	check = vector<int>(N + 1, 0);
	v = vector<vector<int>>(N + 1, vector<int>());
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		check[B]++;
		// A���� Ǯ�� B�� ǰ.
		v[A].push_back(B);
	}
	// check[]==0 �̶�� ���� ���� Ǫ�� ������ ���� ����������
	// �켱���� ť�� �־� ���´�.
	for (int i = 1; i < N + 1; i++)
	{
		if (check[i] == 0)
		{
			problem.push(-i);
		}
	}

	while (1)
	{
		if (problem.empty())break;
		int _top = -problem.top();
		problem.pop();
		cout << _top << " ";
		// top�� �ִ� ���� Ǯ�� Ǯ�� ���� Ǯ��� �ϴ� ���� Ȯ��
		// top�� �ִ� ���� Ǯ������ Ǯ��� �ϴ� ������ ���� Ǯ���� �ϴ� ���� �� --
		// ���� Ǯ�����ϴ� ������ 0�̸� �켱����ť�� �ֱ�
		// 
		for (int i = 0; i < v[_top].size(); i++)
		{
			check[v[_top][i]]--;
			if (check[v[_top][i]] == 0)
			{
				problem.push(-v[_top][i]);
			}
		}
	}
	cout << "\n";

	return 0;
}