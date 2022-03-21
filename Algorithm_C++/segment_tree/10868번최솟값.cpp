#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;

int N,M;
vector<int> numbers;
vector<int> segmentTree;
void setTree(int curNode,int left,int right)
{
    if(left==right) 
    {
        segmentTree[curNode] = numbers[left];
        return;
    }

    int mid = (left + right) / 2;

    setTree(curNode * 2 ,left, mid);
    setTree(curNode * 2 + 1 , mid + 1, right);

    segmentTree[curNode] = min(segmentTree[curNode * 2], segmentTree[curNode * 2 + 1]);
}
int findMinValue(int curNode,int left,int right,int start,int end)
{
    // left , right = 이동하는 범위
    // start , end = 입력 받은 값
    //  범위를 벗어난 경우
    if(left > end || right < start ) return -1;
    
    if(left >= start && right <= end) return segmentTree[curNode];

    int mid = (left + right) / 2;

    int leftSide = findMinValue(curNode * 2,left,mid,start,end);
    int rightSide = findMinValue(curNode * 2 + 1,mid + 1,right,start,end);

    if(leftSide == -1) return rightSide;
    if(rightSide == -1 )return leftSide;
    return min(leftSide,rightSide);
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M;
    numbers = vector<int>(N+1);
    int treeHeight = ceil(log2(N));
    int treeSize = (1 << (treeHeight+1));
    segmentTree.resize(treeSize);

    for(int i=1;i<=N;i++)
    {
        cin>>numbers[i];
    }
    setTree(1,1,N);

    int start,end;
    for(int i=0;i<M;i++)
    {
        cin>>start>>end;
        cout<<findMinValue(1,1,N,start,end)<<"\n"; 
    }

    return 0;
}