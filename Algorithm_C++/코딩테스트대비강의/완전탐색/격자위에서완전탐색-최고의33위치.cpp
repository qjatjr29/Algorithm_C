#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N;
int coin_count=INT_MIN;
vector<vector<int> > map;
// 주어진 구역에서 동전 개수 구하는 함수
int get_num_coin(int row,int col)
{
    int count=0;
    for(int i=row;i<row+3;i++)
    {
        for(int j=col;j<col+3;j++)
        {
            if(map[i][j]==1)count++;
        }
    }
    return count;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    map=vector<vector<int> > (N+1,vector<int>(N+1,0));
    coin_count=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int num;
            cin>>num;
            map[i][j]=num;
        }
    }
    for(int i=0;i<N;i++)
    {
        if(i+3>N)break;
        for(int j=0;j<N;j++)
        {
            if(j+3>N)break;
            coin_count=max(coin_count,get_num_coin(i,j));
        }
    }
    cout<<coin_count<<"\n";
    return 0;
}