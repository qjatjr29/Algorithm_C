#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

string s; // 문자열 s
int a,b; // 알파, 베타 (두 자연수)
map<int,char> alphabet;
char sol(int num)
{
    num -= 4;
    if(num<0)
    {
        num = 26-num;

    }
    return 'a';
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    cin>>a>>b;
    cin>>s;

    for(int i=0;i<26;i++)
    {
        
    }


    return 0;
}