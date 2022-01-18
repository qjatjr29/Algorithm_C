#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
long long ans;
priority_queue<int> grade;
//vector<int> grade;
int main()
{

    cin.tie(NULL);  
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int angry;
        cin>>angry;
        //grade.push_back(angry);
        grade.push(-angry);
    }
    //sort(grade.begin(),grade.end());
    int cnt=1;
    // for(int i=0;i<grade.size();i++)
    // {
    //     ans+=abs(cnt-grade[i]);
    //     cnt++;
    // }
    while(1)
    {
        if(grade.empty())break;
        int curGrade=-grade.top();
        grade.pop();
        ans+=abs(curGrade-cnt);
        cnt++;
    }
    cout<<ans<<"\n";

    return 0;
}