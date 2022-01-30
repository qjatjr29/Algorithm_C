#include <iostream>
#include <vector>
#include <map>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int x=0;
    int y=0;
    int dir=0;
    string command;
    cin>>command;
    for(int i=0;i<command.size();i++)
    {
        char cmd=command[i];
        if(cmd=='R')
            dir=(dir+1)%4;
        else if(cmd=='L')
            dir=(dir-1+4)%4;
        else 
        {
            x+=dx[dir];
            y+=dy[dir];
        }
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}