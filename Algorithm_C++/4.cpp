#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
bool visited[1000];
vector<int> solution(string s) {
    vector<int> answer;


    for (int i = 0; i < s.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            int count = 1;
            int temp = i;
            while (1)
            {
                temp--;
                if (temp < 0)
                {
                    temp = s.size() - 1;
                }
                if (visited[temp])break;
                if (s[i] != s[temp]) break;
                visited[temp] = true;
                count++;
            }
            temp = i;
            while (1)
            {
                temp++;
                if (temp >= s.size()) temp = 0;
                if (visited[temp])break;
                if (s[i] != s[temp]) break;
                visited[temp] = true;
                count++;
            }
            answer.push_back(count);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}