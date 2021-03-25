#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{

	int c;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		stack<char> store;
		string parentheses;
		cin >> parentheses;
		bool check = true;
		for (int j = 0; j < parentheses.size(); j++)
		{
			if (parentheses[j] == '(' || parentheses[j] == '{' || parentheses[j] == '[')
			{
				store.push(parentheses[j]);
			}
			else
			{
				if (store.size() == 0)
				{
					check = false;
					break;
				}
				if (parentheses[j] == ')')
				{
					if (store.top() != '(')
					{
						check = false;
						break;
					}
					else
					{
						store.pop();
					}
				}

				else if (parentheses[j] == '}')
				{
					if (store.top() != '{')
					{
						check = false;
						break;
					}
					else
					{
						store.pop();
					}
				}

				else if (parentheses[j] == ']')
				{
					if (store.top() != '[')
					{
						check = false;
						break;
					}
					else
					{
						store.pop();
					}
				}
			}
		}
		if (store.size() != 0)check = false;
		if (check)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}


	return 0;
}