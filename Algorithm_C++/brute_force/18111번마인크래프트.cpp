#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int N,M,B;
pair<int,int> ans=make_pair(987654321,0);
vector<vector<int> > map;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M>>B;
    map=vector<vector<int> >(N+1,vector<int>(M+1,0));
   
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            int height;
            cin>>height;
            map[i][j]=height;
        }
    }
    for(int i=0;i<=256;i++)
    {
        int temp_B=B;
        int temp_time=0;
        for(int j=0;j<N;j++)
        {
            for(int z=0;z<M;z++)
            {
                int curNode=map[j][z];
                // 제거해야함.
                if(curNode>i)
                {
                    temp_time += (2*(curNode-i));
                    temp_B += (curNode-i);
                }
                // 블록을 꺼내야함.
                else if(curNode<i)
                {
                    temp_B -= (i-curNode);
                    temp_time += (i-curNode);
                } 
            }
        }
        if(temp_B<0)continue;
        else if(ans.first >= temp_time) 
        {
            ans.first=temp_time;
            ans.second=i;
        }
       
    }
    cout<<ans.first<<" "<<ans.second<<"\n";


    return 0;
}