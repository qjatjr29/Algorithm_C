#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
vector<vector<int>> answer;
vector<vector<int>> solution(int rows, int columns) {

    int zeroCount = rows * columns - 1;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    answer = vector<vector<int>>(rows, vector<int>(columns, 0));
    answer[0][0] = 1;
    while (1)
    {
        if (q.empty())break;
        if (zeroCount == 0)break;
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        int lately = answer[cx][cy];

        // 홀수 인경우
        // 다음 수는 짝수가 들어가게 된다.
        if (lately % 2 != 0)
        {
            int ny = cy + 1;
            if (ny >= columns)ny = 0;

            int nextValue = answer[cx][ny];
            if (nextValue == 0)
            {
                zeroCount--;
                answer[cx][ny] = lately + 1;
                q.push(make_pair(cx, ny));
            }


            if (nextValue != 0)
            {
                // 무한 루프 시작..
                if (nextValue % 2 == 0)
                {
                    break;
                }
                answer[cx][ny] = lately + 1;
                q.push(make_pair(cx, ny));
            }
        }
        // 짝수인 경우
        else
        {
            int nx = cx + 1;
            if (nx >= rows)nx = 0;

            int nextValue = answer[nx][cy];

            if (nextValue == 0)
            {
                zeroCount--;
                answer[nx][cy] = lately + 1;
                q.push(make_pair(nx, cy));
            }


            if (nextValue != 0)
            {
                // 무한 루프 시작..
                if (nextValue % 2 != 0)
                {
                    break;
                }
                answer[nx][cy] = lately + 1;
                q.push(make_pair(nx, cy));
            }
        }

    }
    return answer;
}

int main()
{
    vector<vector<int>> result = solution(3, 3);


    return 0;
}