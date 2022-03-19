#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int N;
// 0번째 인덱스 -> x :0 
// 0번째 인덱스에서 queen 위치 : board[0] 값
int board[16];
int answer;
void sol(int cnt)
{
    if(cnt == N)
    {
        answer+=1;
        return;
    }
    for(int i=0;i<N;i++)
    {
        bool chk = true;
        board[cnt] = i;

        // 지금까지 놓인 퀸들의 위치와 지금 놓을 퀸의 위치 비교
        for(int j=0;j<cnt;j++)
        {
            // 퀸 y좌표가 같은 경우.
            if(board[j] == board[cnt])
            {
                chk = false;
                break;
            }
            // 퀸 위치가 대각선인 경우.
            if((cnt-j) == abs(board[cnt]-board[j]))
            {
                chk = false;
                break;
            }
        }
        if(chk) sol(cnt+1);
    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N;
    sol(0);
    cout<<answer<<"\n";



    return 0;
}