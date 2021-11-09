#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


vector<vector<bool>> visited;
vector<string> solution(vector<string> grid, bool clockwise) {
    vector<string> answer;

    // 시계방향
    if (clockwise == true)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            string s = "";
            int limit = i * 2;
            int chk = 0;
            int row = grid.size() - 1;
            while (1)
            {
                if (limit == chk)break;
                s += grid[row][limit - chk];
                chk++;
                s += grid[row][limit - chk];
                chk++;
                row--;
            }
            s += grid[row][0];
            answer.push_back(s);
        }
    }
    else
    {
        for (int i = 0; i < grid.size(); i++)
        {
            string s = "";
            int limit = i * 2;
            int chk = 0;
            int row = grid.size() - 1 - i;
            s += grid[row][grid[row].size() - 1];
            row++;
            while (1)
            {
                if (limit == chk)break;
                s += grid[row][grid[row].size() - 2 - chk];
                chk++;
                s += grid[row][grid[row].size() - 2 - chk];
                chk++;
                row++;
            }

            answer.push_back(s);
        }
    }


    return answer;
}