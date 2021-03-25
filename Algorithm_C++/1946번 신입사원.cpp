#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//bool cmp(pair<int, int> apply1, pair<int, int> apply2)
//{
//	if (apply1.first < apply2.first)return true;
//	else if (apply1.first == apply2.first)
//	{
//		if (apply1.second < apply2.second)return true;
//		else return false;
//	}
//	return false;
//}

int main()
{
	int T;
	int n;
	vector <pair<int, int>> _apply;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		_apply.clear();

		for (int j = 0; j < n; j++)
		{
			int paper, interview;
			cin >> paper >> interview;
			_apply.push_back(make_pair(paper, interview));
		}
		sort(_apply.begin(), _apply.end());

		int result = 1;
		int interview_max = _apply[0].second;
		for (int j = 1; j < n; j++)
		{
			if (interview_max > _apply[j].second)
			{
				result++;
				interview_max = _apply[j].second;
			}
		}
		cout << result << "\n";
	}


	return 0;
}


