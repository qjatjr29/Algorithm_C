#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string word;
string findWord;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	getline(cin, word, '\n');
	getline(cin, findWord, '\n');
	//cin >> word;
	//cin >> findWord;

	int iter = 0;
	bool _break = false;
	while (1)
	{
		if (iter >= word.size() - findWord.size() + 1)break;
		if (_break)break;
		bool check = true;
		for (int i = 0; i < findWord.size(); i++)
		{
			if (iter + i >= word.size())
			{
				check = false;
				_break = true;
				break;
			}
			if (word[iter + i] != findWord[i])
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			iter += findWord.size();
			result++;
		}
		else iter += 1;
	}
	cout << result << "\n";
	return 0;
}