#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int N, L;
vector<int> A;
// 범위안에 있는 작은 수들 모음
// 제일 앞에 있는 것이 제일 작은 수
// 들어오는 수가 원래 있던 것보다 크면 pop 해주면서 넣어주기.
deque<pair<int, int>> dq;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		// deque의 크기는 항상 L
		// i증가 할 수록 최소값 찾아야하는 범위가 달라진다.
		// i-L+1 <= 범위 <= i
		// 범위 벗어난 것 삭제
		if (!dq.empty() && dq.front().second < i - L + 1)
		{
			dq.pop_front();
		}
		int number;
		cin >> number;
		// 오름차순으로 정렬이 되어야 하기 때문에.
		// 지금 입력받은 숫자보다 deque 의 크기가 크다면 pop
		while (1)
		{
			if (dq.empty())break;
			// dq의 값이 입력받은 값보다 작
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
