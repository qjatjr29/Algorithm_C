#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N;
long long B;
vector<vector<int> > matrixs;
vector<vector<int> > multi;
vector<bool> visited;
vector<vector<int> > multiply(vector<vector<int> >cmp1,vector<vector<int> >cmp2)
{

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int z=0;z<N;z++)
            {

            }
        }
    }
 
}
vector<vector<int> > divideConquer(long long size)
{
    vector<vector<int> > temp;
    if(size==1) return matrixs;
    else if(size % 2 ==0)
    {
        temp=divideConquer(size/2);
        return multiply(temp,temp);
    }
    else 
    {
        temp=divideConquer(size-1);
        
    }

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>B;
    matrixs=vector<vector<int> >(N+1,vector<int>(N+1,0));
    multi=vector<vector<int> >(N+1,vector<int>(N+1,0));
    visited = vector<bool>(B+1,false);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>matrixs[i][j];
            multi[i][j]=matrixs[i][j];
        }
    }



    return 0;
}