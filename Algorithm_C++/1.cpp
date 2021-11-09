#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int store[4];

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	int maxIndex = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		int index = arr[i];
		store[index]++;
		if (store[index] > store[maxIndex])
		{
			maxIndex = index;
		}
	}

	for (int i = 1; i <= 3; i++)
	{
		int gap = store[maxIndex] - store[i];
		answer.push_back(gap);
	}

	return answer;

}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);

	vector<int> ans = solution(arr);
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}