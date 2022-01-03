#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _case = 1;
int main()
{
	int L, P, V;
	while (1)
	{
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0)break;
		int _max = 0;
		_max += ((V / P) * L);
		int temp = V - ((V / P) * P);
		if (temp <= L)
		{
			_max += temp;
		}
		else
		{
			_max += L;
		}
		cout << "Case " << _case << ": " << _max << "\n";
		_case++;
	}







	return 0;
}