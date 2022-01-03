#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> number;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N >> M;
	//number = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	int sum = 0;
	number.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		sum += num;
		number.push_back(sum);
	}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << number[end] - number[start - 1] << "\n";
	}

	return 0;
}