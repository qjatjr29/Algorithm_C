#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
vector <pair<int, int>> time;

bool cmp(const pair<int, int>  start, const pair<int, int> finish)
{
	// 빨리끝나는 순으로 리턴.
	if (start.second < finish.second)
	{
		return true;
	}
	// 끝나는 시간이 같으면 
	else if (start.second == finish.second)
	{
		if (start.first < finish.first)return true;
		else return false;
	}
	return false;
}

int main()
{
	int count = 1;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, finish;
		cin >> start >> finish;
		time.push_back(make_pair(start, finish));
	}
	sort(time.begin(), time.end(), cmp);
	int _start, _finish;
	_start = time[0].first;
	_finish = time[0].second;

	for (int i = 1; i < n; i++)
	{
		if (_finish <= time[i].first)
		{
			_finish = time[i].second;
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}

