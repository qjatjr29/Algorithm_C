#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N;
// 0 인지 1 인지 확인하기 위한 bool 변수
int black ,white;
vector<string> map;
string divideConquer(int x, int y,int size)
{
    // 크기가 1*1 인 경우
    if(size==1) return string(1,map[x][y]);

    // 왼쪽 위 부터 같은 값인지 확인
    black=1;
    white=0;
    for(int i=x;i<x+size;i++)
    {
        for(int j=y;j<y+size;j++)
        {
            if(map[i][j]=='1') white=1;
            else black=0;
        }
    }
    // 둘다 존재 -> 다시 분할 정복 
    if(black==0 && white==1)
    {
        // 왼쪽 위, 오른쪽 위, 왼쪽 아래 , 오른쪽 아래 
        // 4방향으로 분할 -> 탐색
        string leftUP=divideConquer(x,y,size/2);
        string rightUP=divideConquer(x,y+(size/2),size/2);
        string leftDOWN=divideConquer(x+(size/2),y,size/2);
        string rightDOWN=divideConquer(x+(size/2),y+(size/2),size/2);
        return "("+leftUP+rightUP+leftDOWN+rightDOWN+")";
    }
    else if(black==0) return "0";
    else return "1";

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    
    for(int i=0;i<N;i++)
    {
        string state;
        cin>>state;
        map.push_back(state);   
    }
    // 맨 왼쪽 위 부터 탐색 시작.
    string ans=divideConquer(0,0,N);
    cout<<ans<<"\n";
    return 0;
}