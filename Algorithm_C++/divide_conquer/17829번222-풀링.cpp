#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
vector<vector<int> >map;
int divideConquer(int x,int y,int size)
{
    int arr[4];
    int count=0;
    if(size==2)
    {
        for(int i=x;i<x+2;i++)
        {
            for(int j=y;j<y+2;j++)
            {
                arr[count]=map[i][j];
                count++;
            }
        }
        sort(arr,arr+4);
        return arr[2];
    }
    else
    {
        arr[0]=divideConquer(x,y,size/2);
        arr[1]=divideConquer(x,y+size/2,size/2);
        arr[2]=divideConquer(x+size/2,y,size/2);
        arr[3]=divideConquer(x+size/2,y+size/2,size/2);
        sort(arr,arr+4);
        return arr[2];
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    map=vector<vector<int> >(N+1,vector<int>(N+1,0));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int number;
            cin>>number;
            map[i][j]=number;
        }
    }
    cout<<divideConquer(0,0,N);

    return 0;
}