#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N, L;
vector<vector<int>> map;
int result;
void slope();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> L;
	map = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int height;
			cin >> height;
			map[i][j] = height;
		}
	}
	slope();
	cout << result << "\n";

	return 0;
}

void slope()
{

	// ����
	for (int i = 0; i < N; i++)
	{
		int temp;
		int temp_count = 1;
		bool check = true;
		temp = map[i][0];
		for (int j = 1; j < N; j++)
		{
			// ���̰� ���� ��� 
			if (temp == map[i][j])
			{
				temp_count++;
			}

			// �ڿ� �� ���� �� ū ���.
			else if (temp < map[i][j])
			{
				// �� Ȯ��. 

				// �տ��� �ذ� ������ ���.
				if (temp_count >= L && temp + 1 == map[i][j])
				{
					temp = map[i][j];
					temp_count = 1;
				}
				// �տ��� �ذ� ���ϴ� ��� 
				else
				{
					check = false;
					break;
				}
			}

			// �ڿ� �� ���� ���� ���� ���
			else
			{
				bool rightCheck = true;
				for (int z = j; z < j + L; z++)
				{
					if (z >= N)
					{
						rightCheck = false;
						break;
					}
					if (map[i][z] + 1 != temp)
					{
						rightCheck = false;
						break;
					}
				}
				if (rightCheck)
				{
					temp_count = 0;
					temp = map[i][j];
					j += (L - 1);
				}
				else
				{
					check = false;
					break;
				}
			}

		}
		if (check)result++;
	}

	// ����
	for (int i = 0; i < N; i++)
	{
		int temp;
		int temp_count = 1;
		bool check = true;
		temp = map[0][i];
		for (int j = 1; j < N; j++)
		{
			// ���̰� ���� ���
			if (temp == map[j][i])
			{
				temp_count++;
			}

			// �ڿ� �� ���� �� ū ���.
			else if (temp < map[j][i])
			{
				// �� Ȯ��. 

				// �տ��� �ذ� ������ ���.
				if (temp_count >= L && temp + 1 == map[j][i])
				{
					temp = map[j][i];
					temp_count = 1;
				}
				// �տ��� �ذ� ���ϴ� ��� 
				else
				{
					check = false;
					break;
				}
			}

			// �ڿ� �� ���� ���� ���� ���
			else
			{
				bool rightCheck = true;
				for (int z = j; z < j + L; z++)
				{
					if (z >= N)
					{
						rightCheck = false;
						break;
					}
					if (map[z][i] + 1 != temp)
					{
						rightCheck = false;
						break;
					}
				}
				if (rightCheck)
				{
					temp_count = 0;
					temp = map[j][i];
					j += (L - 1);
				}
				else
				{
					check = false;
					break;
				}
			}

		}
		if (check)result++;
	}



}
