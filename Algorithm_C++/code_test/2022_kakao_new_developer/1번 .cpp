#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;


int k;
vector<string> id_list;
vector<string> report;
vector<vector<pair<int, string>>> chk;
vector<int> answer;
vector<int> declaration;
void solution();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	solution();


	return 0;
}

void solution()
{
	k = 3;

	/*id_list.push_back("muzi");
	id_list.push_back("frodo");
	id_list.push_back("apeach");
	id_list.push_back("neo");

	report.push_back("muzi frodo");
	report.push_back("apeach frodo");
	report.push_back("frodo neo");
	report.push_back("muzi neo");
	report.push_back("apeach muzi");*/

	id_list.push_back("con");
	id_list.push_back("ryan");

	report.push_back("ryan con");
	report.push_back("ryan con");
	report.push_back("ryan con");
	report.push_back("ryan con");


	int size = id_list.size();
	chk = vector<vector<pair<int, string>>>(size + 1, vector<pair<int, string>>());
	answer = vector<int>(size, 0);
	for (int i = 0; i < report.size(); i++)
	{
		//cout << "i+1번째" << "\n";
		int idx = report[i].find(' ');
		string user = report[i].substr(0, idx);
		string target = report[i].substr(idx + 1, report[i].size());
		bool check = true;
		int targetIndex = 0;
		int userIndex = 0;
		for (int i = 0; i < id_list.size(); i++)
		{
			if (target == id_list[i])
			{
				targetIndex = i;
				for (int j = 0; j < chk[i].size(); j++)
				{
					// 이미 신고한 경우
					if (chk[i][j].second == user)
					{
						check = false;
						break;
					}
				}
			}
			if (user == id_list[i])
			{
				userIndex = i;
			}
		}

		//신고할 수 있는 경우.
		if (check)
		{
			chk[targetIndex].push_back(make_pair(userIndex, user));
		}
	}


	for (int i = 0; i < chk.size(); i++)
	{
		if (chk[i].size() >= k)
		{
			for (int j = 0; j < chk[i].size(); j++)
			{
				int _index = chk[i][j].first;
				answer[_index]++;
			}
		}
	}
	for (int i = 0; i < answer.size() - 1; i++)
	{
		cout << answer[i] << " ";
	}
	cout << answer[answer.size() - 1] << "\n";
}
