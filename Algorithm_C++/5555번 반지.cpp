#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string word;
int N;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> word;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string cmp_word;
		cin >> cmp_word;
		cmp_word += cmp_word;
		if (cmp_word.find(word)!=string::npos)
		{
			result++;
		}
	}
	cout << result << "\n";

	return 0;
}