#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int result;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	for (int i = 0; i < 8; i++)
	{
		string chess;
		cin >> chess;
		for (int j = 0; j < chess.size(); j++)
		{
			if ((i + j) % 2 == 0 && chess[j] == 'F')
			{
				result++;
			}
		}
	}
	cout << result << "\n";

	return 0;
}