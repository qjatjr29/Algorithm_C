#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int N, M;
//vector<string> S;
map<string, int> Sarr;
int result;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		//S.push_back(s);
		Sarr[s] = 1;
	}
	for (int i = 0; i < M; i++)
	{
		string inputString;
		cin >> inputString;
		/*	for (int j = 0; j < S.size(); j++)
			{
				if (inputString == S[j])
				{
					result++;
					break;
				}
			}*/
		if (Sarr[inputString] == 1)result++;
	}
	cout << result << "\n";

	return 0;
}