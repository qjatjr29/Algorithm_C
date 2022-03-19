#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int N,K;
int chk;
int words[50];
int answer;
void sol(int cnt,int idx)
{
    if(cnt == K)
    {
        int count =  0;
        for(int i=0;i<N;i++)
        {
            // words[i] 를 읽을 수 있는 경우.
            if((words[i] & chk)== words[i]) count++;
        }
        answer = max(answer,count);
        return;
    }
    for(int i=idx;i<26;i++)
    {
        // i 번째를 처음 넣었을 때 
        if((chk & ( 1<< i))==0)
        {
            chk |= (1<<i);
            sol(cnt+1,i);
            chk &= ~(1<<i);
        }
    }

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>K;
    
    for(int i=0;i<N;i++)
    {
        string str;
        cin>>str;
        int temp =0;
        temp |= 1 << ('a'-'a');
        temp |= 1 << ('c'-'a');
        temp |= 1 << ('t'-'a');
        temp |= 1 << ('i'-'a');
        temp |= 1 << ('n'-'a');
        str = str.substr(4,str.size()-8);
        for(int i=0;i<str.size();i++)
        {
            temp |= 1 << (str[i]-'a');
        }
        words[i] = temp;
    
    }

    if(K<5) cout<<0<<"\n";
    else if(K==26) cout<<N<<"\n";
    else
    {
        chk |= 1 << ('a'-'a');
        chk |= 1 << ('c'-'a');
        chk |= 1 << ('t'-'a');
        chk |= 1 << ('i'-'a');
        chk |= 1 << ('n'-'a');
        sol(5,0);
        cout<<answer<<"\n";
    }

    return 0;
}