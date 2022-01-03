#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N;
string s;
stack<double> answer;
double alphaNum[27];
double calcNum(double num1, double num2, char oper);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;

	cin >> s;

	for (int i = 1; i <= N; i++)
	{
		double value;
		cin >> value;
		alphaNum[i] = value;
	}

	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		int nextNum = c - '0' - 16;

		if (nextNum < 1)
		{
			double firstNum = answer.top();
			answer.pop();
			double secondNum = answer.top();
			answer.pop();
			double calcResult = calcNum(secondNum, firstNum, c);
			answer.push(calcResult);
		}
		else
		{
			answer.push(alphaNum[nextNum]);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer.top() << "\n";



	return 0;
}

double calcNum(double num1, double num2, char oper)
{
	if (oper == '*')
	{
		return num1 * num2;
	}
	else if (oper == '+')
	{
		return num1 + num2;
	}
	else if (oper == '/')
	{
		return num1 / num2;
	}
	else if (oper == '-')
	{
		return num1 - num2;
	}

}
