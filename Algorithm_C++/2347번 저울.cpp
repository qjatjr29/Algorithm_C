#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
vector<int> v;
int result;
int main()
{
	// 현재 인덱스의 추까지 차례로 더하는 값 까지는 
	// 0 ~ 인덱스 만큼의 추로 만들 수 있다.
	// ex) 추를 1 2 3 4 --> 10 까지는 무조건 만들 수 있다.
	// 하나씩 더하는 원소는 현재 인덱스의 추보다 낮아야 계산이 가능
	// 
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int number;
		cin >> number;
		v.push_back(number);
	}

	sort(v.begin(), v.begin() + N);

	for (int i = 0; i < N; i++)
	{
		if (result + 1 < v[i])
		{
			break;
		}
		result += v[i];
	}
	cout << result + 1 << "\n";


	return 0;
}