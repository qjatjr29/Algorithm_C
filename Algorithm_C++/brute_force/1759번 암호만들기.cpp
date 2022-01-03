#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


int L, C;
vector<char> alpha;
queue<string> result;
queue<char> temp;
void setPassword(int idx, string s, int chk1, int chk2);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		alpha.push_back(c);
	}
	sort(alpha.begin(), alpha.end());

	setPassword(0, "", 0, 0);

	while (1)
	{
		if (result.empty())break;
		cout << result.front() << "\n";
		result.pop();
	}



	return 0;
}

void setPassword(int idx, string s, int chk1, int chk2)
{
	if (s.size() == L && chk1 >= 1 && chk2 >= 2)
	{
		result.push(s);
		return;
	}
	for (int i = idx; i < C; i++)
	{
		s += alpha[i];
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
		{
			chk1++;
			setPassword(i + 1, s, chk1, chk2);
			s = s.substr(0, s.size() - 1);
			chk1--;
		}
		else
		{
			chk2++;
			setPassword(i + 1, s, chk1, chk2);
			s = s.substr(0, s.size() - 1);
			chk2--;
		}

	}


}
