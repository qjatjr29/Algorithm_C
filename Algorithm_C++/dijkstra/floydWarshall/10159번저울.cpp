#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int N ,M;
int comp[101][101];
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    
    for(int i=0;i<M;i++)
    {
        int heavy, light;
        cin>>heavy>>light;
        comp[heavy][light] = 1;
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++)
            {
                // j > i 이고 i > k 이면 j > k 성립
                if(comp[j][i] ==1 && comp[i][k]) comp[j][k] = 1;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        int cnt = 0; 
        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            // 서로 아무 관련도 없는 경우.
            if(comp[i][j] == 0 && comp[j][i] == 0 ) cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}