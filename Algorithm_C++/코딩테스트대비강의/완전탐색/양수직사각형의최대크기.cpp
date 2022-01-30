#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n,m;
int maxSum=-1;
vector<vector<int> > map;
bool calcRect(int row,int col,int row_length,int col_length)
{
    bool checkRect=true;
    for(int i=row;i<row+row_length;i++)
    {
        for(int j=col;j<col+col_length;j++)
        {
            // 양수가 아닌 경우.
            if(map[i][j]<=0)
            {
                checkRect=false;
                break;
            }
        }
        if(!checkRect)break;
    }
    return checkRect;
}
void chkRect(int row_length,int col_length)
{
    bool chk;
    for(int i=0;i<n;i++)
    {
        if(i+row_length>n)break;
        for(int j=0;j<m;j++)
        {
            if(j+col_length>m)break;
            chk=calcRect(i,j,row_length,col_length);
            //chk==true : 가능한 경우.
            if(chk)break;
        }
        if(chk)break;
    }
    if(chk)
    {
        maxSum=max(maxSum,(row_length)*(col_length));
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m;
    map=vector<vector<int> >(n+1,vector<int>(m+1,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int number;
            cin>>number;
            map[i][j]=number;
        }
    }
    //직사각형 크기 정하기
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            chkRect(i,j);
        }
    }
    cout<<maxSum<<'\n';
    return 0;
}