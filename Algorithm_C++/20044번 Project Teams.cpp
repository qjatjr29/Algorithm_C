#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int n;
deque<int> coding;
int result = 987654321;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < 2 * n; i++)
	{
		int num;
		cin >> num;
		coding.push_back(num);
	}
	sort(coding.begin(), coding.end());
	int idx = 0;
	while (1)
	{
		if (coding.empty())break;
		int student1 = coding.front();
		coding.pop_front();
		int student2 = coding.back();
		coding.pop_back();

		result = min(result, student1 + student2);

	}
	cout << result << "\n";

	return 0;
}
