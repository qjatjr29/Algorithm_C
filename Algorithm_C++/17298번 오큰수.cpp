#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> store;
stack<int> bigger;
int N;
//void bigger(int curindex);
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		store.push_back(number);
	}
	vector<int> result(store.size(), -1);
	//bigger(0);
	for (int i = 0; i < N; i++)
	{
		while (!bigger.empty() && store[bigger.top()] < store[i])
		{
			result[bigger.top()] = store[i];
			bigger.pop();
		}
		bigger.push(i);
	}
	//result.push_back(-1);
	for (int i = 0; i < N - 1; i++)
	{
		cout << result[i] << " ";
	}
	cout << result[N - 1] << "\n";

	return 0;
}

/*
void bigger(int curindex)
{
	if (curindex == N)return;
	bool check = false;
	for (int i = curindex+1; i < N; i++)
	{
		if (store[curindex] < store[i])
		{
			check = true;
			result.push(store[i]);
			break;
		}
	}
	if (!check)result.push(-1);
	return bigger(curindex + 1);
}
*/