#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int customers,menu,deleteCnt; // 참여한 손님수, 팔고 있는 메뉴 개수
vector<vector<int> > like; // 고객들의 선호도
int upperFive[1001];  // 각 고객들의 선호도가 5이상인게 몇개인지 체크
vector<vector<int> > upperFiveMenu;  // i번째 메뉴의 선호도가 5이상인 경우 고객index 저장
bool visited[17];
int answer;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>customers>>menu>>deleteCnt;
    like = vector<vector<int> > (customers,vector<int>(menu));
    upperFiveMenu = vector<vector<int > > (17,vector<int >());


    for(int i=1;i<=customers;i++)
    {
        for(int j=1;j<=menu;j++)
        {
            int number;
            cin>>number;
            if(number>=5)
            {
                upperFive[i]++;
                upperFiveMenu[j].push_back(i);
            }
        }
    }
   
    answer = customers;
    for(int i=0;i<deleteCnt;i++)
    {
        int leave = 18;
        int delMenuIdx = 0;
        for(int j=1;j<=menu;j++)
        {
            // 이미 삭제된 메뉴
            if(visited[j]) continue;
            int temp = 0; 
            for(int z=0;z<(int)upperFiveMenu[j].size();z++)
            {
                if(upperFive[upperFiveMenu[j][z]]-1 == 0)
                {
                    temp ++;
                }
            }
            if(leave > temp)
            {
                leave = temp;
                delMenuIdx = j;
            }
        }
        visited[delMenuIdx] = true;
        for(int j=0;j<(int)upperFiveMenu[delMenuIdx].size();j++)
        {
            upperFive[upperFiveMenu[delMenuIdx][j]]--;
        }
        answer -= leave;
    }
    cout<<answer<<"\n";


    return 0;
}