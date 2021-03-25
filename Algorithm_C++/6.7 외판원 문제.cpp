#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


void cost(vector<int> W[], vector<int> _check, int check, int N, int min, int index, int startindex, int& result);
// check는 N-1번 확인했는지 확인하는 것.
int main()
{
	int N;
	cin >> N;
	int result = 10000001;
	vector<int> W[11];
	vector<int> check; // 간 도시인지 확인하는 벡터
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			W[i].push_back(number);
			check.push_back(0);
		}
	}
	for (int z = 0; z < N; z++)
	{
		cost(W, check, 0, N, 0, z, z, result);
	}
	cout << result << "\n";
	return 0;
}

void cost(vector<int> W[], vector<int> _check, int check, int N, int min, int index, int startindex, int& result)
{
	if (check == N && startindex == index)
	{
		if (result > min)result = min;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (W[index][i] == 0)continue; // 연결되지 않을경우 넘어감

		if (_check[index] == 0)   // 가지않은 도시일때 
		{
			_check[index] = 1;
			min += W[index][i];
			if (min < result)
			{
				cost(W, _check, check + 1, N, min, i, startindex, result);
			}
			_check[index] = 0; // 초기화 
			min -= W[index][i]; // 한번 돌면 다시 값 초기화 해서 비교다시 해야함.
		}

	}

}
