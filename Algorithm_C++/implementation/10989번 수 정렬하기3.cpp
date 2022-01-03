#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[10001];
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		arr[number]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << "\n";
		}
	}
	return 0;
}