#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
vector<long long> liquid;
long long sum = 2000000001;
pair<long long, long long> result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;

	liquid = vector<long long>(N, 0);

	for (int i = 0; i < N; i++)
	{
		int cost;
		cin >> cost;
		liquid[i] = cost;
	}
	int left = 0;
	int right = liquid.size() - 1;
	while (1)
	{
		if (left >= right)break;
		long long chk1 = liquid[left];
		long long chk2 = liquid[right];

		if (abs(chk1 + chk2) < sum)
		{
			sum = abs(chk1 + chk2);
			result = make_pair(chk1, chk2);
		}

		// ���� ���� ���� -> ������ ũ�⸦ ���δ�.
		if (chk1 + chk2 < 0)
		{
			left++;
		}
		// ���� ���� ��� -> ����� ũ�⸦ ���δ�.
		else right--;
	}
	cout << result.first << " " << result.second << "\n";

	return 0;
}
