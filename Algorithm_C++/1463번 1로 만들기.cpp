#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N;
int result = 0;
vector<int> calculation;
void cal(int temp);
int main()
{
	cin >> N;
	calculation.push_back(0);
	calculation.push_back(0);
	calculation.push_back(1);
	calculation.push_back(1);
	if (N >= 4)
	{
		cal(4);
	}

	cout << calculation[N] << "\n";

	return 0;
}

void cal(int temp)
{
	if (temp == N + 1)return;
	int comparison = 987654321;
	if (temp % 3 == 0)
	{
		comparison = min(comparison, calculation[temp / 3]);
	}
	if (temp % 2 == 0)
	{
		comparison = min(comparison, calculation[temp / 2]);
	}
	comparison = min(comparison, calculation[temp - 1]);
	calculation.push_back(comparison + 1);
	return cal(temp + 1);
}


/*
void cal(int temp)
{
	if (temp == N)return;
	if (temp *3 <= N)
	{
		result++;
		return cal(temp * 3);
	}
	if (temp *2  <= N)
	{
		result++;
		return cal(temp * 2);
	}
	temp = temp + 1;
	result++;
	return cal(temp);

}
*/