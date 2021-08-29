#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N;
vector<int> number;
vector<char> oper;
int result = -987654321;
int calc(char oper, int num1, int num2);
void bracket(int curIndex, int answer);
int main()
{

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	string cmd;
	cin >> cmd;
	for (int i = 0; i < cmd.size(); i++)
	{
		char c = cmd[i];
		int num = c - '0';

		if (num <= 9 && num >= 0)
		{
			number.push_back(num);
		}
		else
		{
			oper.push_back(c);
		}
	}
	bracket(0, 0);
	cout << result << "\n";

	return 0;
}

int calc(char oper, int num1, int num2)
{
	int returnNum = 0;
	switch (oper)
	{
	case '+':
		returnNum = num1 + num2;
		break;
	case '*':
		returnNum = num1 * num2;
		break;
	case '-':
		returnNum = num1 - num2;
		break;
	default:
		break;
	}
	return returnNum;
}

void bracket(int curIndex, int answer)
{
	if (curIndex > oper.size())
	{
		result = max(result, answer);
		return;
	}

	char curOperation;

	if (curIndex == 0)
	{
		curOperation = '+';
	}
	else curOperation = oper[curIndex - 1];

	int answerTemp;

	// 괄호를 추가한 경우
	if (curIndex + 1 <= oper.size())
	{
		int temp = calc(oper[curIndex], number[curIndex], number[curIndex + 1]);
		answerTemp = calc(curOperation, answer, temp);
		bracket(curIndex + 2, answerTemp);
	}

	// 괄호 추가 안하고 그냥 넘어가는 경우.
	answerTemp = calc(curOperation, answer, number[curIndex]);
	bracket(curIndex + 1, answerTemp);

	return;
}
