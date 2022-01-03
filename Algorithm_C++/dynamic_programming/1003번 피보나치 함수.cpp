#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, N;
int Fibo[41] = { 0,1 };

int main()
{
	cin.tie(NULL); cin.sync_with_stdio(false);
	for (int i = 2; i < 41; i++)
	{
		Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
	}
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N;
		if (N == 0)cout << "1 0" << "\n";
		else if (N == 1)cout << "0 1" << "\n";
		else
		{
			cout << Fibo[N - 1] << " " << Fibo[N] << "\n";
		}
	}
}

