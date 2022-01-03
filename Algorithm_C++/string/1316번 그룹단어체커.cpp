#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
vector<int> alpha;
int result;
int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		alpha = vector<int>(27, 0);
		string s;
		cin >> s;
		bool check = false;

		alpha[s[0] - 97] = 1;
		for (int j = 1; j < s.size(); j++)
		{
			if (s[j] != s[j - 1])
			{
				if (alpha[s[j] - 97] == 0)
				{
					alpha[s[j] - 97] = 1;
				}
				else
				{
					check = true;
					break;
				}
			}
		}
		if (!check)result++;
	}
	cout << result << "\n";
	return 0;
}