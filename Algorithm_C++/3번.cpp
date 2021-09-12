#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

vector<pair<int, int>> result;
vector<int> fees;
vector<string> records;
vector<pair<int, pair<int, int>>> parking;
void calcFees();
int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	calcFees();
	return 0;
}

void calcFees()
{
	vector<int> answer;
	fees.push_back(180);
	fees.push_back(5000);
	fees.push_back(10);
	fees.push_back(600);

	records.push_back("05:34 5961 IN");
	records.push_back("06:00 0000 IN");
	records.push_back("06:34 0000 OUT");
	records.push_back("07:59 5961 OUT");
	records.push_back("07:59 0148 IN");
	records.push_back("18:59 0000 IN");
	records.push_back("19:09 0148 OUT");
	records.push_back("22:59 5961 IN");
	records.push_back("23:00 5961 OUT");


	int basicTime = fees[0];
	int basicCost = fees[1];
	int addTime = fees[2];
	int addCost = fees[3];

	for (int i = 0; i < records.size(); i++)
	{
		int idx = records[i].find(' ');
		string carTime = records[i].substr(0, idx);
		int _idx = carTime.find(':');
		int hour = stoi(carTime.substr(0, _idx));
		int minutes = stoi(carTime.substr(_idx + 1, carTime.size() - 1));
		string temp = records[i].substr(idx + 1, records[i].size());
		idx = temp.find(' ');
		string cNumber = temp.substr(0, idx);
		int carNumber = stoi(cNumber);
		string type = temp.substr(idx + 1, temp.size());
		//cout << hour <<":"<< minutes << " " << carNumber << " " << type << "\n";

		// 주차장 입장
		if (type == "IN")
		{
			parking.push_back(make_pair(carNumber, make_pair(hour, minutes)));
		}

		// 주차장에서 나가는 경우
		else
		{
			for (int j = 0; j < parking.size(); j++)
			{
				// 찾은 경우
				if (parking[j].first == carNumber)
				{

					// 시간 계산
					int hourGap = hour - parking[j].second.first;
					int minuteGap = minutes - parking[j].second.second;
					parking.erase(parking.begin() + j, parking.begin() + j + 1);
					if (minuteGap < 0)
					{
						hourGap--;
						minuteGap += 60;
					}
					minuteGap += (hourGap * 60);

					bool chk = true;

					for (int z = 0; z < result.size(); z++)
					{
						// 이미 한번 나갔다 다시 들어온경우
						if (result[z].first == carNumber)
						{
							chk = false;
							result[z].second += minuteGap;
							break;
						}
					}
					// 처음 들어갔다 나가는 경우.
					if (chk)
					{
						result.push_back(make_pair(carNumber, minuteGap));
					}
					break;
				}
			}
		}
	}

	for (int i = 0; i < parking.size(); i++)
	{
		int inHour = parking[i].second.first;
		int inMin = parking[i].second.second;
		// 시간 계산
		int hourGap = 23 - inHour;
		int minuteGap = 59 - inMin;
		if (minuteGap < 0)
		{
			hourGap--;
			minuteGap += 60;
		}
		minuteGap += (hourGap * 60);
		bool chk = true;

		for (int z = 0; z < result.size(); z++)
		{
			// 이미 한번 나갔다 다시 들어온경우
			if (result[z].first == parking[i].first)
			{
				chk = false;
				result[z].second += minuteGap;
				break;
			}
		}
		// 처음 들어갔다 나가는 경우.
		if (chk)
		{
			result.push_back(make_pair(parking[i].first, minuteGap));
		}
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i].second <= basicTime)
		{
			cout << basicCost << "\n";
		}
		else
		{
			double d = double(result[i].second - basicTime) / double(addTime);
			int a = ceil(d);

			int resultCost = basicCost + a * addCost;
			//cout << resultCost << "\n";
			answer.push_back(resultCost);
		}
		//cout << answer[i].second << " ";
	}



}
