#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int N; // 키워드의 개수
string K; // 키워드
int T; // 단어의 개수
string W; // 입력중인 단어
vector<string> keyword;
vector<int> answer;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>K;
        keyword.push_back(K);
    }

    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>W;
        int cnt = 0 ;
        for(int j=0;j<keyword.size();j++)
        {
            bool chk = true;
            for(int z=0;z<W.size();z++)
            {
                if(keyword[j][z]!=W[z])
                {
                    chk = false;
                    break;
                }
            }
            if(chk) cnt++;
        }
        answer.push_back(cnt);
    }
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<"\n";
    }

    return 0;
}