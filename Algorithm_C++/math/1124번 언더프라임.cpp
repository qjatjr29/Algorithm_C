#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int A, B;
vector<int> store;
bool check(int number);
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> A >> B;
	store = vector<int>(B + 1, 0);
	for (int i = 2; i <= B; i++)
	{
		if (check(i))
		{
			store[i] = 1;
		}
		// ¦�� �� 2* ¦��/2 �̹Ƿ� �Ҽ��� 1�� �þ��. (���μ� ���ؽ�)
		else if (i % 2 == 0)
		{
			store[i] = store[i / 2] + 1;
		}
		// Ȧ�� 
		// �������� ���� ���� ���� �����ſ� +1
		else if (i % 2 == 1)
		{
			for (int j = 3; j <= i; j++)
			{
				if (i % j == 0)
				{
					store[i] = store[i / j] + 1;
					break;
				}
			}
		}
	}
	for (int i = A; i <= B; i++)
	{
		if (check(store[i]))result++;
	}
	cout << result << "\n";

	return 0;
}


//�Ҽ����� �ƴ��� Ȯ��.
bool check(int number)
{
	if (number == 1)return false;
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)return false;
	}
	return true;
}
