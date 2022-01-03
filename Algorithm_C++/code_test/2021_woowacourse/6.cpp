#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string solution(double time, vector<vector<string>> plans) {
    string answer = "";

    for (int i = 0; i < plans.size(); i++)
    {
        double need = 0.0;
        string name = plans[i][0];

        string startTime = plans[i][1];
        string arrivalTime = plans[i][2];

        int sindex = startTime.find("M");
        int aindex = arrivalTime.find("M");

        int sTime = stoi(startTime.substr(0, sindex - 1));
        int aTime = stoi(arrivalTime.substr(0, aindex - 1));

        if (startTime.find("P") != string::npos)
        {
            sTime += 12;
        }
        if (arrivalTime.find("P") != string::npos)
        {
            aTime += 12;
        }


        if ((double)sTime < 9.5)
        {
            need += 8.5;
        }
        else if (18 - (double)sTime >= 0)
        {
            need += 18 - (double)sTime;
        }

        if ((double)aTime >= 18)
        {
            need += 5.0;
        }
        else if ((double)aTime - 13 >= 0)
        {
            need += (double)aTime - 13;
        }
        if (need < time)
        {
            answer = name;
        }

    }



    return answer;
}

int main()
{
    double time = 3.5;
    vector<vector<string>> plans;
    plans = vector<vector<string>>(2, vector<string>());
    plans[0].push_back("È«Äá");
    plans[0].push_back("11PM");
    plans[0].push_back("9AM");
    plans[1].push_back("¿¤¿¡ÀÌ");
    plans[1].push_back("3PM");
    plans[1].push_back("2PM");
    cout << solution(time, plans) << "\n";
    return 0;
}