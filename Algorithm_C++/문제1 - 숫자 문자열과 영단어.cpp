#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> result;
int solution(string s);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string s;
	cin >> s;
	solution(s);


	cout << solution(s) << "\n";

	return 0;
}

int solution(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		int checknum = s[i] - '0';

		if (0 <= checknum && checknum < 10)
		{
			result.push(s[i] - '0');
		}
		else
		{

			char check = s[i];
			switch (check)
			{
			case 'z':
				result.push(0);
				i += 3;
				break;
			case 'o':
				result.push(1);
				i += 2;
				break;
			case 't':
				if (s[i + 1] == 'w')
				{
					result.push(2);
					i += 2;
					break;
				}
				else
				{
					result.push(3);
					i += 4;
					break;
				}
			case 'f':
				if (s[i + 1] == 'o')
				{
					result.push(4);
					i += 3;
					break;
				}
				else
				{
					result.push(5);
					i += 3;
					break;
				}
			case 's':
				if (s[i + 1] == 'i')
				{
					result.push(6);
					i += 2;
					break;
				}
				else
				{
					result.push(7);
					i += 4;
					break;
				}
			case 'e':
				result.push(8);
				i += 4;
				break;
			case 'n':
				result.push(9);
				i += 3;
				break;
			default:
				break;
			}
		}
	}

	int returnNumber = 0;
	int count = 0;
	while (1)
	{
		if (result.empty())break;
		int number = result.front();
		result.pop();
		returnNumber = (returnNumber * 10) + number;
	}
	return returnNumber;
}
