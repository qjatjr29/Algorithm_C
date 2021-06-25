#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N;
vector<pair<int, string>> title;
string result;
vector<string> result_arr;
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string book_title;
		cin >> book_title;
		bool check = true;
		for (int j = 0; j < title.size(); j++)
		{
			if (title[j].second == book_title)
			{
				title[j].first++;
				check = false;
			}
		}
		if (check)
		{
			title.push_back(make_pair(1, book_title));
		}
	}
	sort(title.begin(), title.end());
	int MaxNum = title[title.size() - 1].first;
	result = title[title.size() - 1].second;
	result_arr.push_back(result);
	for (int i = title.size() - 2; i >= 0; i--)
	{
		if (title[i].first == MaxNum)
		{
			result_arr.push_back(title[i].second);
		}
		else if (title[i].first < MaxNum)
		{
			break;
		}

	}
	sort(result_arr.begin(), result_arr.end());
	cout << result_arr[0] << "\n";
	return 0;
}