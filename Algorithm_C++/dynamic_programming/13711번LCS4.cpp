#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> firstArr;
vector<int> secondArr;
vector<int> dp;
void sol()
{
    dp.push_back(secondArr[1]);
    for(int i=2;i<=N;i++)
    {
        if(dp[dp.size()-1] < secondArr[i]) dp.push_back(secondArr[i]);
        else
        {
            int idx = lower_bound(dp.begin(),dp.end(),secondArr[i]) - dp.begin();
            dp[idx] = secondArr[i];
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    firstArr= vector<int>(N+1);
    secondArr = vector<int>(N+1);
    int number;
    // 첫번째 수열의 숫자들을 치환 -> 1,2,3,4,5 ... 순서로 만들기.
    for(int i=1;i<=N;i++)
    {
        cin>>number;
        firstArr[number] = i;
    }
    // 첫 번째 수열의 값을 치환한 값으로 두번째 수열을 재 구성.
    for(int i=1;i<=N;i++)
    {
        cin>>number;
        secondArr[i] = firstArr[number];
    }
    // 첫번째 수열은 12345.. 이므로
    // 두번째 수열에서 가장 증가하는 부분 수열의 길이를 구하면 끝.
    sol();
    cout<<dp.size()<<"\n";
    return 0;
}