#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int E, S, M;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> E >> S >> M;

	while (1)
	{
		result++;
		int e = result % 15;
		int s = result % 28;
		int m = result % 19;
		if (e == 0) e = 15;
		if (s == 0)s = 28;
		if (m == 0)m = 19;
		if (e == E && s == S && m == M)	break;

	}
	cout << result << "\n";


	return 0;
}