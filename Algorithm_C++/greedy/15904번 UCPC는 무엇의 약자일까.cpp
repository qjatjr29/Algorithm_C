#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

string s;
vector<bool> check;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	check = vector<bool>(4, false);
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'U')
		{
			if (check[0] == false)
			{
				check[0] = true;
			}
		}
		if (s[i] == 'C')
		{
			if (check[0] == true && check[1] == false)
			{
				check[1] = true;
			}
			else if (check[2] == true && check[3] == false)
			{
				check[3] = true;
			}
		}
		if (s[i] == 'P')
		{
			if (check[1] == true && check[2] == false)
			{
				check[2] = true;
			}
		}
	}
	if (check[3] == true)
	{
		cout << "I love UCPC" << "\n";
	}
	else
	{
		cout << "I hate UCPC" << "\n";
	}
	return 0;
}