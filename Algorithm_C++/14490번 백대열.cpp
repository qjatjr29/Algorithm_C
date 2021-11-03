#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string s;
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> s;

	int index = s.find(":");
	string c1 = s.substr(0, index);
	string c2 = s.substr(index + 1, s.size());


	int num1 = stoi(c1);
	int num2 = stoi(c2);
	int modnumber = gcd(num1, num2);
	cout << num1 / modnumber << ":" << num2 / modnumber << "\n";

	return 0;
}