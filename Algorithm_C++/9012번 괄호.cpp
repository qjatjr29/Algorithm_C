#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		stack<char> parenthesis;
		bool check = true;
		string vps;
		cin >> vps;
		for (int j = 0; j < vps.size(); j++)
		{
			if (vps[j] == '(')parenthesis.push(vps[j]);
			else
			{
				// ( 괄호가 없을때 .. -> 에러
				if (parenthesis.size() == 0)
				{
					check = false;
					break;
				}
				else
				{
					parenthesis.pop();
				}
			}
		}
		if (parenthesis.size() != 0)check = false;
		if (check)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}

	return 0;
}