#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;


string S;
vector<string> sArray;
int main()
{

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	getline(cin, S);

	string temp = "";
	int index = 0;
	bool chk = false;
	while (1)
	{

		if (index >= S.size())
		{
			if (temp != "") sArray.push_back(temp);
			break;
		}

		if (chk == true)
		{
			if (S[index] == '>')
			{
				temp += S[index];
				sArray.push_back(temp);
				temp = "";
				index++;
				chk = false;
				continue;
			}
			temp += S[index];
			index++;
		}
		else
		{
			if (S[index] == ' ')
			{
				sArray.push_back(temp);
				sArray.push_back(" ");
				temp = "";
				index++;
				continue;
			}
			if (S[index] == '<')
			{
				sArray.push_back(temp);
				temp = "";
				temp += S[index];
				index++;
				chk = true;
				continue;
			}
			temp += S[index];
			index++;
		}
	}

	for (int i = 0; i < sArray.size(); i++)
	{
		if (sArray[i][0] == '<')
		{
			cout << sArray[i];
		}
		else
		{
			reverse(sArray[i].begin(), sArray[i].end());
			cout << sArray[i];
		}
	}
	cout << "\n";

	return 0;
}