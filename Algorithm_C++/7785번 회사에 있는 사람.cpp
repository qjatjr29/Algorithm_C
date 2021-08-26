#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int n;
vector<string> company;
map<string, bool> check;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name;
		string cmd;
		cin >> name >> cmd;

		if (check.count(name))
		{
			if (cmd == "enter")
			{
				check[name] = true;
			}
			else
				check[name] = false;

			continue;
		}

		company.push_back(name);
		check[name] = true;

	}
	sort(company.begin(), company.end());

	for (int i = company.size() - 1; i >= 0; i--)
	{
		if (check[company[i]] == true)
		{
			cout << company[i] << "\n";
		}
	}


	return 0;
}