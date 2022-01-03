#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T;
int K;
long long result;
priority_queue<long long> file;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++)
	{
		cin >> K;
		result = 0;
		for (int i = 0; i < K; i++)
		{
			long long  number;
			cin >> number;
			file.push(-number);
		}
		while (1)
		{
			if (file.size() == 1)break;
			long long temp = -file.top();
			file.pop();
			long long temp1 = -file.top();
			file.pop();
			file.push(-(temp + temp1));
			result += (temp + temp1);
		}
		while (1)
		{
			if (file.empty())break;
			file.pop();
		}
		cout << result << "\n";
	}


	return 0;
}