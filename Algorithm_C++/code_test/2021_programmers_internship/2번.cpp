#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

vector<vector<int>> upgrade;
int solution(int time, int gold, vector<vector<int>> upgrade);
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<int> a;
	a.push_back(0);
	a.push_back(5);
	upgrade.push_back(a);
	vector<int> b;
	b.push_back(100);
	b.push_back(4);
	upgrade.push_back(b);
	vector<int> c;
	c.push_back(200);
	c.push_back(3);
	upgrade.push_back(c);

	int ans = solution(11, 1000, upgrade);
	cout << ans << "\n";

	return 0;
}
int solution(int time, int gold, vector<vector<int>> upgrade) {
	int answer = -1;


	int lv1Time = upgrade[0][1];
	answer = int(time / lv1Time) * gold;
	
	int lv2Cost = upgrade[1][0];
	int lv2Time = upgrade[1][1];
	int lv3Cost = upgrade[2][0];
	int lv3Time = upgrade[2][1];

	int cost = 0;
	int tempTime = time;
	int lv2 = 0;
	bool chk = true;
	// 2레벨로 업그레이드
	while (1)
	{
		if (cost >= lv2Cost)break;
		tempTime -= lv1Time;
		if (tempTime < 0)
		{
			chk = false;
			break;
		}
		cost += gold;
	}
	if (chk==true)
	{
		// lv2로 업그레이드 하고 남은 돈
		lv2 = cost - lv2Cost;
		cost = lv2;
		lv2 += gold * int(tempTime / lv2Time);
		answer = max(answer, lv2);
		bool chk2 = true;
		int lv3 = 0;
		while (1)
		{
			if (cost >= lv3Cost)break;
			tempTime -= lv2Time;
			if (tempTime < 0)
			{
				chk2 = false;
				break;
			}
			cost += gold;
		}
		if (chk2 == true)
		{
			lv3 = cost - lv3Cost;
			lv3 += gold * int(tempTime / lv3Time);
			answer = max(answer, lv3);
		}
	}

	return answer;
}