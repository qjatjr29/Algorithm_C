#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <istream>
using namespace std;

vector<string> s;
bool str(string st);
int main()
{
	string input;
	while (1)
	{
		getline(cin, input, '.');
		//input= input.substr(0, input.size());
		//input.erase(std::remove(input.begin(), input.end(), '\n'));
		if (input == "\n")break;
		s.push_back(input);

		//cout <<input << "\n";
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (str(s[i]) == true)
		{
			cout << "yes" << "\n";
		}
		else
		{
			cout << "no" << "\n";
		}
	}

	return 0;
}

bool str(string st)
{
	bool check = true;
	stack<char> chk;
	int size = st.size();
	for (int i = 0; i < size; i++)
	{
		if (st[i] == '(' || st[i] == '[')
		{
			chk.push(st[i]);
		}
		else if (st[i] == ')')
		{
			if (chk.size() == 0)
			{
				check = false;
				break;
			}
			char top = chk.top();
			if (top != '(')
			{
				check = false;
				break;
			}
			else
			{
				chk.pop();
			}
		}
		else if (st[i] == ']')
		{
			if (chk.size() == 0)
			{
				check = false;
				break;
			}
			char top = chk.top();
			if (top != '[')
			{
				check = false;
				break;
			}
			else
			{
				chk.pop();
			}
		}
	}
	if (check)
	{
		if (chk.size() != 0)return false;
		else return true;
	}
	else return false;

}
