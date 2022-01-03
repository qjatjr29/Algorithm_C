#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int arr[21];
int M;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;

		if (s == "add")
		{
			int num;
			cin >> num;
			arr[num] = 1;
		}
		else if (s == "check")
		{
			int num;
			cin >> num;
			cout << arr[num] << "\n";
		}
		else if (s == "remove")
		{
			int num;
			cin >> num;
			arr[num] = 0;
		}
		else if (s == "toggle")
		{
			int num;
			cin >> num;
			if (arr[num] == 0)arr[num] = 1;
			else arr[num] = 0;
		}
		else if (s == "all")
		{
			for (int i = 1; i <= 20; i++)
			{
				arr[i] = 1;
			}
		}
		else
		{
			for (int i = 1; i <= 20; i++)
			{
				arr[i] = 0;
			}
		}
	}

	return 0;
}