#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

int N;
priority_queue<int> card;
void compare();
int result;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int cardNum;
		cin >> cardNum;
		card.push(-cardNum);
	}
	if (N == 1)
	{
		cout << 0 << "\n";
	}
	else
	{
		compare();
		cout << result << "\n";
	}

	return 0;
}

void compare()
{
	int size;

	while (1)
	{
		size = card.size();
		if (size == 1)break;

		int firstTop = -card.top();
		card.pop();
		int secondTop = -card.top();
		card.pop();
		int addResult = firstTop + secondTop;
		card.push(-addResult);
		result += addResult;

	}

}
