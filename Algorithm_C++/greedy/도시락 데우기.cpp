#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second)return true;
	else if (a.second == b.second)
	{
		if (a.first > b.first)return true;
		else return false;
	}
	return false;
}
int main()
{
	int c;
	vector<int> heating;
	vector<int> eating;
	vector<pair<int, int>> time;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cin >> n;
		heating.clear();
		eating.clear();
		time.clear();
		for (int j = 0; j < n; j++)
		{
			int heatingtime;
			cin >> heatingtime;
			heating.push_back(heatingtime);
		}
		for (int j = 0; j < n; j++)
		{
			int eatingtime;
			cin >> eatingtime;
			eating.push_back(eatingtime);
		}
		for (int j = 0; j < n; j++)
		{
			time.push_back(make_pair(heating[j], eating[j]));
		}
		// 마지막 먹는 시간 + 음식 데웠던 시간 => 총 걸리는 시간.
		// 먹는 시간이 큰 것부터 시작. (내림차순)
		// 먹는 시간이 같을경우는 데우는 시간이 큰 것이 앞으로
		// 먹는 시간 순으로 정렬 
		sort(time.begin(), time.end(), cmp);
		int _time = 0;
		int result = 0;
		for (int j = 0; j < n; j++)
		{
			_time += time[j].first;
			result = max(result, _time + time[j].second);
		}
		/*
		for (int j = 0; j < n; j++)
		{
			_time += time[j].first;

		}
		_time += time[n-1].second;
		cout << _time << "\n";
		*/
		cout << result << "\n";
	}



	return 0;
}