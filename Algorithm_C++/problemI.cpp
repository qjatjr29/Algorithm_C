#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#include <stack>
#include <map>
using namespace std;

int N;
vector<pair<int, pair<int, int>>> player;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int b, p, q, r;
		cin >> b >> p >> q >> r;
		int mulNum = p * q * r;
		int sumNum = p + q + r;
		player.push_back(make_pair(mulNum, make_pair(sumNum, b)));
	}
	sort(player.begin(), player.end());
	for (int i = 0; i < 2; i++)
	{
		cout << player[i].second.second << " ";
	}
	cout << player[2].second.second << "\n";

	return 0;
}