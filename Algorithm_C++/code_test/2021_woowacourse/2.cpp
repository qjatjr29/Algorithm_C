#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


string solution(vector<string>log)
{
	string answer = "";
	int result = 0;
	for (int i = 0; i < log.size(); i += 2)
	{
		string starttime = log[i];
		string stoptime = log[i + 1];

		int sHour = stoi(starttime.substr(0, 2));
		int sMinute = stoi(starttime.substr(3, 5));
		int eHour = stoi(stoptime.substr(0, 2));
		int eMinute = stoi(stoptime.substr(3, 5));

		int gap = 60 * (eHour - sHour) + eMinute - sMinute;
		if (eMinute - sMinute < 0)
		{
			gap = 60 * ((eHour - 1) - sHour) - eMinute + sMinute;
		}
		else
			gap = 60 * (eHour - sHour) + eMinute - sMinute;

		if (gap >= 5)
		{
			if (gap >= 105)
			{
				result += 105;
			}
			else result += gap;
		}
	}
	int h = result / 60;
	int m = result % 60;

	if (h < 10)
	{
		answer += ("0" + to_string(h));
	}
	else answer += to_string(h);
	answer += ":";
	if (m < 10)
	{
		answer += ("0" + to_string(m));
	}
	else answer += to_string(m);



	return answer;
}

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	vector<string> log;
	//log.push_back("08:30");
	//log.push_back("09:00");
	//log.push_back("14:00");
	//log.push_back("16:00");
	//log.push_back("16:01");
	//log.push_back("16:06");
	//log.push_back("16:07");
	//log.push_back("16:11");
	log.push_back("01:00");
	log.push_back("08:00");
	log.push_back("15:00");
	log.push_back("15:04");
	log.push_back("23:00");
	log.push_back("23:59");

	cout << solution(log) << "\n";

	return 0;
}