#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> coin;
//vector<int> result;
//void makecoin(int index,int& count,int sum);
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int value;
		cin >> value;
		//coin.push_back(value);
		if (value < K)
		{
			coin.push_back(value);
		}
	}
	//for (int i = N - 1; i >= 0; i--)
	//{
	//	int count = 1;
	//	if (result.size() != 0)break;
	//	makecoin(i, count, coin[i]);
	//}
	int min = 0;
	int sum = 0;
	for (int i = coin.size(); i > 0; i--)
	{
		int temp = 0;
		if (K == sum)break;
		while (1)
		{
			if (K < sum + coin[i - 1])break;
			temp++;
			sum += coin[i - 1];
		}
		//sum -= coin[i - 1];
		min += temp;
	}
	/*int _max = 0;
	for (int i = 0; i < result.size(); i++)
	{
		_max = min(_max, result[i]);
	}
	cout << _max << "\n";*/
	cout << min << "\n";

	return 0;
}

/*
void makecoin(int index,int& count,int sum)
{
	if (index < 0)return;
	if (sum > K)return;
	if (sum == K)
	{
		result.push_back(count);
		return;
	}
	while (1)
	{
		if (sum + coin[index] > K)break;
		sum += coin[index];
		count++;
	}
	return makecoin(index-1, count, sum);
}
*/
