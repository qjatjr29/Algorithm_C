#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<int> positiveNumber;
vector<int> negativeNumber;
queue<int> Zero;
long long result;
void calcSum();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (num > 0)
		{
			positiveNumber.push_back(num);
		}
		else if (num == 0)
		{
			Zero.push(num);
		}
		else
		{
			negativeNumber.push_back(num);
		}
	}
	sort(positiveNumber.begin(), positiveNumber.end());
	sort(negativeNumber.begin(), negativeNumber.end());
	calcSum();
	cout << result << "\n";


	return 0;
}

void calcSum()
{
	int idx = positiveNumber.size() - 1;
	bool chk = true;
	while (1)
	{
		if (idx < 0)break;
		if (idx == 0)
		{
			chk = false;
			break;
		}
		int a = positiveNumber[idx];
		if (a == 1)
		{
			chk = false;
			break;
		}
		idx--;
		int b = positiveNumber[idx];
		if (b == 1)
		{
			idx++;
			chk = false;
			break;
		}
		long long  plusNum = a * b;
		result += plusNum;
		idx--;
	}
	if (!chk)
	{
		for (int i = 0; i <= idx; i++)
		{
			result += positiveNumber[i];
		}
	}
	chk = true;
	idx = 0;

	if (negativeNumber.size() > 0)
	{
		while (1)
		{
			if (idx > negativeNumber.size() - 1)break;
			if (idx == negativeNumber.size() - 1)
			{
				chk = false;
				break;
			}
			int a = negativeNumber[idx];
			idx++;
			int b = negativeNumber[idx];
			long long plusNum = a * b;
			result += plusNum;
			idx++;
		}
		if (!chk)
		{
			if (Zero.empty())
			{
				result += negativeNumber[idx];
			}
		}
	}

}
