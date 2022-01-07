#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, Q;
int number[100001];
vector<long long> segmentTree;
long long setTree(int node, int start, int end)
{
    if (start == end)
        return segmentTree[node] = number[start];
    int mid = (start + end) / 2;
    long long left = setTree(node * 2, start, mid);
    long long right = setTree(node * 2 + 1, mid + 1, end);
    segmentTree[node] = left + right;
    return segmentTree[node];
}
long long sum(int node, int start, int end, int left, int right)
{
    // 범위 밖에 있는 경우
    if (left > end || right < start)
        return 0;
    // 범위에 속해 있는 경우
    if (left <= start && end <= right)
    {
        return segmentTree[node];
    }
    // 범위에 겹쳐 있는 경우
    // 왼쪽, 오른쪽 경우 들어간다.
    int mid = (start + end) / 2;
    long long left_value = sum(node * 2, start, mid, left, right);
    long long right_value = sum(node * 2 + 1, mid + 1, end, left, right);

    return left_value + right_value;
}
void exchange(int node, int start, int end, int index, long long value)
{
    // 범위에 없는 경우
    if (index < start || index > end)
        return;

    segmentTree[node] += value;
    // 범위에 속하는 경우
    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    exchange(node * 2, start, mid, index, value);
    exchange(node * 2 + 1, mid + 1, end, index, value);
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    //input
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        int integer;
        cin >> integer;
        number[i] = integer;
    }
    // set tree
    int tree_height = ceil(log2(N));
    long long tree_size = (1 << (tree_height + 1));
    segmentTree.resize(tree_size);
    setTree(1,0,N-1);
    // simulate
    for (int i = 0; i < Q; i++)
    {
        int start, end, index;
        long long value,result,gap;
        cin >> start >> end >> index >> value;
        if(start>end)
        {
            result=sum(1,0,N-1,end-1,start-1);
        }
        else result=sum(1,0,N-1,start-1,end-1);
        cout<<result<<"\n";
        gap=value-number[index-1];
        number[index-1]=value;
        exchange(1,0,N-1,index-1,gap);
    }

    return 0;
}