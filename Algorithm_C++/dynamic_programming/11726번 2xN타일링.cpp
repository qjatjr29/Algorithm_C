#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> TILING;
void square(int curindex);

int main()
{

	cin >> n;
	TILING.push_back(1);
	TILING.push_back(2);
	if (n > 2)
	{
		square(2);
	}
	cout << TILING[n - 1] << "\n";


	return 0;

}

void square(int curindex)
{
	if (curindex == n)return;

	int number = TILING[curindex - 2] + TILING[curindex - 1];
	number = (number + 10007) % 10007;
	TILING.push_back(number);
	square(curindex + 1);
}
