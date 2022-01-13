#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int col, row;
// 아래, 위, 오른쪽, 왼쪽 순.
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int> > board;
queue<pair<int, pair<int, int> > > mine;
int result;
int moving(int curCol, int curRow, int type, int direction)
{
    int count = 0;
    // 얼마나 이동할 수 있는지 보는 경우
    if (type == 0)
    {
        while (1)
        {
            curCol += dx[direction];
            curRow += dy[direction];
            // 기저 사례
            if (curCol < 0 || curCol >= col || curRow < 0 || curRow >= row)
                break;
            // 이동 가능한 경우 (빈칸)
            if (board[curCol][curRow] == 0)
            {
                count++;
            }
            // 이동 가능. 빈칸이 아님.
            else if (board[curCol][curRow] > 0 && board[curCol][curRow] < 6)
            {
                continue;
            }
            // 이동 할 수 없는 경우 (상대편 있는 경우.)
            else
                break;
        }
        return count;
    }
    // 이동 시키는 경우
    else
    {
        while (1)
        {
            curCol += dx[direction];
            curRow += dy[direction];
            // 기저 사례
            if (curCol < 0 || curCol >= col || curRow < 0 || curRow >= row)
                break;
            // 이동 가능한 경우 (빈칸)
            if (board[curCol][curRow] == 0)
            {
                board[curCol][curRow] = 1;
                result--;
            }
            // 이동 가능. 빈칸이 아님.
            else if (board[curCol][curRow] > 0 && board[curCol][curRow] < 6)
            {
                continue;
            }
            // 이동 할 수 없는 경우 (상대편 있는 경우.)
            else
                break;
        }
        return count;
    }
}

void calEmpty(int type, int curCol, int curRow)
{
    int curCount = 0;
    int selectDirection;
    int testCount;
    pair<int,int> selDirection;
    int counts[4];
    int dir;
    int tempCount;
    if(type==1){
        for (int i = 0; i < 4; i++)
        {
            testCount = moving(curCol, curRow, 0, i);
            if (curCount < testCount)
            {
                curCount = testCount;
                selectDirection = i;
            }
        }
        moving(curCol, curRow, 1, selectDirection);
    }
    if(type==2){
        for (int i = 0; i < 4; i+=2)
        {
            testCount = moving(curCol, curRow, 0, i) + moving(curCol, curRow, 0, i + 1);
            if (curCount < testCount)
            {
                curCount = testCount;
                selectDirection = i;
            }
        }
        moving(curCol, curRow, 1, selectDirection);
        moving(curCol, curRow, 1, selectDirection + 1);
    }
    if(type==3)
    {
        testCount = moving(curCol, curRow, 0, 0) + moving(curCol, curRow, 0, 2);
        if (curCount < testCount)
        {
            curCount = testCount;
            selDirection = make_pair(0,2);
        }
        testCount = moving(curCol, curRow, 0, 0) + moving(curCol, curRow, 0, 3);
        if (curCount < testCount)
        {
            curCount = testCount;
            selDirection = make_pair(0,3);
        }
        testCount = moving(curCol, curRow, 0, 1) + moving(curCol, curRow, 0, 2);
        if (curCount < testCount)
        {
            curCount = testCount;
            selDirection = make_pair(1,2);
        }
        testCount = moving(curCol, curRow, 0, 1) + moving(curCol, curRow, 0, 3);
        if (curCount < testCount)
        {
            curCount = testCount;
            selDirection = make_pair(1,3);
        }
        moving(curCol, curRow, 1, selDirection.first);
        moving(curCol, curRow, 1, selDirection.second);
    }
    if(type==4)
    {
        // up , down , right, left
        counts[0]=moving(curCol,curRow,0,1);
        counts[1]=moving(curCol,curRow,0,0);
        counts[2]=moving(curCol,curRow,0,2);
        counts[3]=moving(curCol,curRow,0,3);
        for(int i=0;i<4;i++)
        {
            tempCount=0;
            for(int j=0;j<4;j++)
            {
                if(i==j)continue;
                tempCount+=counts[j];
            }
            if(curCount<tempCount)
            {
                curCount=tempCount;
                dir=i;
            }
        }
        for(int i=0;i<4;i++)
        {
            if(i==dir)continue;
            moving(curCol,curRow,1,i);
        }
    }
    if(type==5)
    {
        for(int i=0;i<4;i++)
        {
            moving(curCol,curRow,1,i);
        }
    }
   
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> col >> row;
    board = vector<vector<int> >(col + 1, vector<int>(row + 1, 0));
    result = col * row;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            int state;
            cin >> state;
            board[i][j] = state;
            if (state > 0)
            {
                result--;
            }
            if (state > 0 && state < 6)
            {
                mine.push(make_pair(state, make_pair(i, j)));
            }
        }
    }
   
    while (1)
    {
        if (mine.empty())
            break;
        int type = mine.front().first;
        int curCol = mine.front().second.first;
        int curRow = mine.front().second.second;
        mine.pop();
        calEmpty(type,curCol,curRow);
    }
  
    cout<<result<<"\n";
    return 0;
}