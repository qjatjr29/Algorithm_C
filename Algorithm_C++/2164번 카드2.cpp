#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	queue<int> card;
	for (int i = 1; i <= N; i++)
	{
		card.push(i);
	}
	if (card.size() == 1)
	{
		cout << card.front() << "\n";
	}
	else
	{
		while (1)
		{
			card.pop();
			if (card.size() == 1)break;
			int temp = card.front();
			card.pop();
			card.push(temp);
		}
		cout << card.front() << "\n";
	}

	return 0;
}