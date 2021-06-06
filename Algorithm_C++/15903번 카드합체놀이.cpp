#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
priority_queue<long long> card;
void calCard();
long long result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		long long number;
		cin >> number;
		card.push(-number);
	}
	calCard();
	while (1)
	{
		if (card.empty())break;
		long long cardNum = -card.top();
		result += cardNum;
		card.pop();
	}
	cout << result << "\n";
	return 0;
}

void calCard()
{
	int count = 0;
	while (1)
	{
		if (count == m)break;
		long long firstNum = -card.top();
		card.pop();
		long long secondNum = -card.top();
		card.pop();
		long long sum = firstNum + secondNum;
		card.push(-sum);
		card.push(-sum);
		count++;
	}
}
