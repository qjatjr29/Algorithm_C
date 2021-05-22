#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

string s;
vector<string> str;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		str.push_back(s);
		s.erase(s.begin(), s.begin() + 1);
	}
	sort(str.begin(), str.end());
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << "\n";
	}
	return 0;
}