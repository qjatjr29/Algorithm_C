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
	// ���� �ε����� �߱��� ���ʷ� ���ϴ� �� ������ 
	// 0 ~ �ε��� ��ŭ�� �߷� ���� �� �ִ�.
	// ex) �߸� 1 2 3 4 --> 10 ������ ������ ���� �� �ִ�.
	// �ϳ��� ���ϴ� ���Ҵ� ���� �ε����� �ߺ��� ���ƾ� ����� ����
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