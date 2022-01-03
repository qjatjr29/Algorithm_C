#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int n, m;
// map ����
int map[1002][1002];
// �� �� �ִ� ���簢�� ���� ���� 
int square[1002][1002];
int Maxlength;
int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	cin >> n >> m;

	// �ʱ�ȭ �۾�.
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		for (int j = 0; j < m; j++)
		{
			int number = a[j] - '0';
			if (number == 1)
			{
				square[i][j] = 1;
				map[i][j] = 1;
			}
		}
	}

	// ������ 2x2 �̻��� ��.
	if (n > 1 && m > 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				// �ڱⰡ 1�� ���� �ֺ��� ���簢���� �Ǵ��� Ȯ�� 
				if (map[i][j] == 1)
				{
					// �ֺ��� �ϳ��� 1�� �ƴϸ� ���簢���� �� �� ����.
					// 0 �� �ϳ��� ����
					if (square[i - 1][j] != 0 && square[i][j - 1] != 0 && square[i - 1][j - 1] != 0) {
						if (square[i - 1][j] != 1 && square[i][j - 1] != 1 && square[i - 1][j - 1] != 1)
						{
							// �ֺ� 3�� ���߿� ���� ���� �� +1 �� 
							// ���簢���� �� �� �ִ� ����
							int w = min(square[i - 1][j], square[i][j - 1]);
							w = min(w, square[i - 1][j - 1]);
							square[i][j] = w + 1;
						}
						else
						{
							// �ϳ��� ���� 1�̸� �̰� ������ ���簢����
							// �ִ���̴� 2��.
							square[i][j] = 2;
						}
					}
				}

				// �ݺ��� ���鼭 �ִ� ���� ���� ���Ѵ�.
				Maxlength = max(Maxlength, square[i][j]);
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (Maxlength == 1)break;
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					Maxlength = 1;
					break;
				}
			}
		}

	}

	// ���� ���ϴ°� ���� * ����
	cout << pow(Maxlength, 2) << "\n";

	return 0;
}