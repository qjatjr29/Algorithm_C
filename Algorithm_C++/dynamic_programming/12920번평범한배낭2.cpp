#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

struct Thing
{
    int weight;
    int value;
};
vector<Thing> things;
int N,M;
int V,C,K;
int answer;
// i : 물건의 번호, j : 배낭의 무게
vector<vector<int> > dp;
void sol()
{
    
    for(int i=1;i<things.size();i++)
    {
        for(int j=1;j<=M;j++)
        {
            // 물건 못담으면 현재 물건을 못넣었을 때
            // 이전 물건까지 넣은 값이 최대값이므로
            // 미리 설정
            dp[i][j] = dp[i-1][j];
            // 현재 물건의 무게가 j 보다 작을때 (물건 담을 수 있을 때)
            if(j >= things[i].weight)
            {
                // 이 물건을 넣기전 최대 값과 이 물건의 가치를 더한 값
                dp[i][j] = 
                max(dp[i-1][j], dp[i-1][j-things[i].weight] + things[i].value);
            }
            answer = max(answer,dp[i][j]);
        }
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M; // 물건 개수, 가방의 최대 무게
    
    Thing first = {0,0};
    things.push_back(first);
    for(int i=0;i<N;i++)
    {
        cin>>V>>C>>K;
        // j -> 1 , 2, 4, 8 ,....
        // K==11 -> 1, 1, 3, 6 으로 나누면
        // 1 ~ 11 까지의 모든 경우를 나타낼 수 있다.
        // 따라서 k개를 만들 수 있는 경우의 수로 나누어
        // 무게, 만족도를 곱해서 저장해둔다.
        for(int j=K; j>0;j>>=1) 
        {
            int size = j - (j>>1);
            Thing temp;
            temp.weight = V * size;
            temp.value = C * size;
            things.push_back(temp);
        }
    }
    dp = vector<vector<int> > (things.size(),vector<int>(M+1));
    sol();
    
    cout<<answer<<"\n";

    return 0;
}