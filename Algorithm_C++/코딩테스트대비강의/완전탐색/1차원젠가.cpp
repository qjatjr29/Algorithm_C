#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int n;
int block[101];
int temp[101];
void remove_block(int size)
{
    memset(temp,0,sizeof(temp));
    int endoftemp=1;
    
    for(int i=1;i<=size;i++)
    {
        if(block[i]!=0)
        {
            temp[endoftemp]=block[i];
            endoftemp++;
        }
    }
    for(int i=1;i<endoftemp;i++)
    {
        block[i]=temp[i];
    }
    
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int number;
        cin>>number;
        block[i]=number;
    }
    for(int i=0;i<2;i++)
    {
        int start,end;
        cin>>start>>end;
        for(int j=start;j<=end;j++)
        {
            block[j]=0;
        }
        remove_block(n);
        n=n-(end-start+1);
    }
    cout<<n<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<block[i]<<"\n";
    }
    return 0;
}
