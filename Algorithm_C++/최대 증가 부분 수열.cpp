#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n;
vector<int> subsequence;
vector<int> result;
void setsubsequence(vector<int> subsequence, vector<int> result, int curindex);
int main()
{
	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		subsequence.clear();
		result.clear();
		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			subsequence.push_back(number);
		}
		result.push_back(1);
		setsubsequence(subsequence, result, 1);
	}



	return 0;
}

void setsubsequence(vector<int> subsequence, vector<int> result, int curindex)
{
	if (curindex == n)
	{
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			if (max < result[i])max = result[i];
		}
		cout << max << "\n";
		return;
	}
	int count = -1;
	bool check = false;
	for (int i = 0; i < curindex; i++)
	{
		if (subsequence[curindex] > subsequence[i])
		{
			if (count < result[i])
			{
				count = result[i];
				check = true;
			}
		}
	}
	if (check)
	{
		result.push_back(count + 1);
	}
	else
	{
		result.push_back(1);
	}
	setsubsequence(subsequence, result, curindex + 1);

}
