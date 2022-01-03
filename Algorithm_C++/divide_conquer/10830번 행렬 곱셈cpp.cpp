#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& row, vector<vector<int>>& col, int N);
vector<vector<int>> matrix(vector<vector<int>>& curmatrix, vector<vector<int>>& result, long long B, int N);

int main()
{
	int N;
	long long int B;
	cin >> N >> B;
	// N*N 행렬 B 제곱!
	// 행렬 값 저장
	vector<vector<int>> _matrix(N, vector<int>(N, 0));
	// 결과 값 저장하는 벡터
	vector<vector<int>> result(N, vector<int>(N, 0));


	// 행렬값 저장.
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

// 행렬 곱하는 함수
vector<vector<int>> multiply(vector<vector<int>>& row, vector<vector<int>>& col, int N)
{
	// 곱한 결과 저장 하는 벡터
	// n크기만큼 0으로 초기화 한 벡터
	vector<vector<int>> store(N, vector<int>(N, 0));

	// store 벡터에 계산한 결과값 저장.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < N; z++)
			{
				store[i][j] += (row[i][z] * col[z][j]);
				store[i][j] %= 1000;
			}
			//store[i][j] %= 1000;
		}
	}

	return store;
}

vector<vector<int>> matrix(vector<vector<int>>& curmatrix, vector<vector<int>>& result, long long B, int N)
{
	// 2로 계속 나누다가 마지막에 1일때 리턴.
	if (B == 1) return result;

	vector<vector<int>> temp(N, vector<int>(N, 0));
	// 2의 배수일때.
	if (B % 2 == 0)
	{
		// 2로 계속 나눠줌.
		// 2n -> n,n 으로 나눈거
		temp = matrix(curmatrix, result, (B / 2), N);
		// n,n 으로 나눴으니깐 다시 n*n 해줘야함.
		return multiply(temp, temp, N);
	}
	// 1이 아니고 2의 배수가 아닐때
	// n/n 나누고 한번더 곱해주는 식.
	// n-1 해주면 짝수. --> temp에 짝수일때 값 리턴 받고 마지막에 리턴할때 한번더 곱해줌.
	else
	{
		temp = matrix(curmatrix, result, B - 1, N);
	}
	// 한번 더 곱해주기 
	return multiply(temp, curmatrix, N);
}
