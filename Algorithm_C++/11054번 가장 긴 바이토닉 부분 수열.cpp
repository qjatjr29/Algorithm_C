#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> A;
int _left[1001];
int _right[1001];
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	A = vector<int>(N + 1, 0);
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		A[i] = number;
	}
	for (int i = 0; i < N; i++)
	{
		_left[i] = 1;
		for (int j = 0; j < N; j++)
		{
			if (A[i] > A[j] && _left[i] < _left[j] + 1)
			{
				_left[i] = _left[j] + 1;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--)
	{
		_right[i] = 1;
		for (int j = N - 1; j >= 0; j--)
		{
			if (A[i] > A[j] && _right[i] < _right[j] + 1)
			{
				_right[i] = _right[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (result < _left[i] + _right[i] - 1)
		{
			result = _left[i] + _right[i] - 1;
		}
	}
	cout << result << "\n";
	return 0;
}