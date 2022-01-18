#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

string formula;
vector<string> result;
stack<int> open;
vector<pair<int,int> > open_close;
// 괄호 쌍에서 방문한 인덱스인지 확인.
bool visited[201];
// string에서 제외한 인덱스 표시
bool exclude[201];
void findFormula(int parenthesis_index)
{
    string s="";
    // 괄호 쌍을 하나라도 지우고.
    if(parenthesis_index>0)
    {
        for(int i=0;i<formula.size();i++)
        {
            // 제외 안된 인덱스
            if(exclude[i]==false)
            {
                s+=formula[i];
            }
        }

        result.push_back(s);
    }
    for(int i=parenthesis_index;i<open_close.size();i++)
    {
        if(visited[i]==true)continue;
        int nextOpenIndex=open_close[i].first;
        int nextCloseIndex=open_close[i].second;
        visited[i]=true;
        exclude[nextOpenIndex]=true;
        exclude[nextCloseIndex]=true;
        findFormula(parenthesis_index+1);
        visited[i]=false;
        exclude[nextOpenIndex]=false;
        exclude[nextCloseIndex]=false;
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>formula;
    for(int i=0;i<formula.size();i++)
    {
        char letter = formula[i];
        // 가장 최근에 나온 ( 문자 스택에 넣어 놓기.
        if(letter=='(') open.push(i);
        // ) 문자 나오면 가장 최근에 넣은 ( 문자와 쌍을 이루어 벡터에 저장.
        else if(letter==')')
        {
            open_close.push_back(make_pair(open.top(),i));
            // stack 하나 비우기 
            open.pop();
        }
    }
    findFormula(0);
    sort(result.begin(),result.end());
    result.erase(unique(result.begin(),result.end()),result.end());
    for(int i=0;i<result.size();i++)
    {

        cout<<result[i]<<"\n";
    }
      

    return 0;
}