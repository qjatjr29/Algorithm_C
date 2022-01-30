#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
int jump=987654321;
vector<int> node;
void jumpjump(int index,int count)
{
    if(index==n-1)
    {
        jump=min(jump,count);
        return;
    }
    int canJump=node[index];
    for(int i=1;i<=canJump;i++)
    {
        if(index+i>=n)break;
        jumpjump(index+i,count+1);
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        node.push_back(num);
    }

    jumpjump(0,0);
    if(jump==987654321)cout<<-1<<"\n";
    else cout<<jump<<"\n";

    return 0;
}