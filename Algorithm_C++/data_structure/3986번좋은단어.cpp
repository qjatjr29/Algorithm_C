#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N;
int ans;
stack<char> word;
void emptyWord()
{
    while(1)
    {
        if(word.empty())break;
        word.pop();
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string str;
        cin>>str;
        emptyWord();
        for(int i=0;i<str.size();i++)
        {
            if(word.empty())
            {
                word.push(str[i]);
            }
            else if(word.top()==str[i])
            {
                word.pop();
            }
            else 
            {
                word.push(str[i]);
            }
        }
        if(word.empty())ans++;
    }
    cout<<ans<<"\n";
    return 0;
}