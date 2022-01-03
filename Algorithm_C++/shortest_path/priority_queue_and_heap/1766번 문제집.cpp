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
		// A부터 풀고 B를 품.
		v[A].push_back(B);
	}
	// check[]==0 이라는 것은 먼저 푸는 문제가 없는 문제임으로
	// 우선순위 큐에 넣어 놓는다.
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
		// top에 있는 문제 풀고 풀고 나서 풀어야 하는 문제 확인
		// top에 있는 문제 풀었으니 풀어야 하는 문제중 먼저 풀려야 하는 문제 수 --
		// 먼저 풀려야하는 문제가 0이면 우선순위큐에 넣기
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