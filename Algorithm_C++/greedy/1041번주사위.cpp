#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

long long N;
vector<int> dice;
long long ans;
void DiceSum()
{
    // 높이 (마지막 층 -1 까지)
    // n>2 -> 2*n + 2(n-2) - 제일 작은 경우 // 4* 두번째로 작은 경우
    if (N > 2)
    {
        long long temp = (4 * N - 4) * dice[0] + 4 * dice[1];
        ans += (N - 1) * temp;
    }
    else if (N == 2)
    {
        ans += (4 * dice[0] + 4 * dice[1]);
    }

    // 마지막 층
    // 가장 작은 수 -> N*N 개
    // 두번째로 작은수 -> 4*N-4
    // 세번째로 작은수 -> 4
    if (N > 2)
    {
        ans += N * N * dice[0] + (4 * N - 4) * dice[1] + 4 * dice[2];
    }
    else if (N == 2)
    {
        ans += 4 * (dice[0] + dice[1] + dice[2]);
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N;
    dice = vector<int>(3, 1000000);
    if (N == 1)
    {
        vector<int> diceOne;
        for(int i=0;i<6;i++)
        {
            int number;
            cin>>number;
            diceOne.push_back(number);
        }
        sort(diceOne.begin(),diceOne.end());
        for(int i=0;i<diceOne.size()-1;i++)
        {
            ans+=diceOne[i];
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            int number;
            cin >> number;
            if (i < 3)
            {
                dice[i] = number;
            }
            else if (dice[5 - i] > number)
            {
                dice[5 - i] = number;
            }
        }
        // A-F , B - E , C- D 쌍
        // 0-5, 1-4, 2-3
        sort(dice.begin(), dice.end());
        // for(int i=0;i<dice.size();i++)
        // {
        //     cout<<dice[i]<<"\n";
        // }

        DiceSum();
    }
    cout << ans << "\n";
    return 0;
}