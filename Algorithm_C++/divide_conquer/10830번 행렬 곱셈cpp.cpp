#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > multiply(vector<vector<int> > &row, vector<vector<int> > &col, int N);
vector<vector<int> > matrix(vector<vector<int> > &curmatrix, vector<vector<int> > &result, long long B, int N);

int main()
{
	int N;
	long long int B;
	cin >> N >> B;
	// N*N ��� B ����!
	// ��� �� ����
	vector<vector<int> > _matrix(N, vector<int>(N, 0));
	// ��� �� �����ϴ� ����
	vector<vector<int> > result(N, vector<int>(N, 0));

	// ��İ� ����.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int number;
			cin >> number;
			_matrix[i][j] = number;
			result[i][j] = number;
		}
	}

	result = matrix(_matrix, result, B, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] % 1000 << " ";
		}
		cout << "\n";
	}

	return 0;
}

// ��� ���ϴ� �Լ�
vector<vector<int> > multiply(vector<vector<int> > &row, vector<vector<int> > &col, int N)
{
	// ���� ��� ���� �ϴ� ����
	// nũ�⸸ŭ 0���� �ʱ�ȭ �� ����
	vector<vector<int> > store(N, vector<int>(N, 0));

	// store ���Ϳ� ����� ����� ����.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < N; z++)
			{
				store[i][j] += (row[i][z] * col[z][j]);
				store[i][j] %= 1000;
			}
			// store[i][j] %= 1000;
		}
	}

	return store;
}

vector<vector<int> > matrix(vector<vector<int> > &curmatrix, vector<vector<int> > &result, long long B, int N)
{
	// 2�� ��� �����ٰ� �������� 1�϶� ����.
	if (B == 1)
		return result;

	vector<vector<int> > temp(N, vector<int>(N, 0));
	// 2�� ����϶�.
	if (B % 2 == 0)
	{
		// 2�� ��� ������.
		// 2n -> n,n ���� ������
		temp = matrix(curmatrix, result, (B / 2), N);
		// n,n ���� �������ϱ� �ٽ� n*n �������.
		return multiply(temp, temp, N);
	}
	// 1�� �ƴϰ� 2�� ����� �ƴҶ�
	// n/n ������ �ѹ��� �����ִ� ��.
	// n-1 ���ָ� ¦��. --> temp�� ¦���϶� �� ���� �ް� �������� �����Ҷ� �ѹ��� ������.
	else
	{
		temp = matrix(curmatrix, result, B - 1, N);
	}
	// �ѹ� �� �����ֱ�
	return multiply(temp, curmatrix, N);
}
