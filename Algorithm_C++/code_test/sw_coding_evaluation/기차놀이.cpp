#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	int division= (N / 26)+1;
	int rest = N % 26;
	if (rest == 0)
	{
		rest = 26;
		division = N / 26;
	}
	double findNum = double(rest) / division;
	int result = ceil(findNum);

	cout << char(result+96) << "\n";



	return 0;
}