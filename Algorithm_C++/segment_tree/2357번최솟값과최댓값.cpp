#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;

int N, M;
vector<int> numbers;
vector<int> minTree;
vector<int> maxTree;
void setTree(int curNode, int start, int end)
{
    if (start == end)
    {
        minTree[curNode] = numbers[start];
        maxTree[curNode] = numbers[start];
        return;
    }

    int mid = (start + end) / 2;

    setTree(curNode * 2, start, mid);
    setTree(curNode * 2 + 1, mid + 1, end);

    minTree[curNode] = min(minTree[curNode * 2], minTree[curNode * 2 + 1]);
    maxTree[curNode] = max(maxTree[curNode * 2], maxTree[curNode * 2 + 1]);
}

int minValue(int node, int left, int right, int start, int end)
{
    // 범위 안에 없는 경우.
    if (end < left || start > right)
        return -1;
    // 범위 안에 있는 경우
    if (left >= start && right <= end)
        return minTree[node];

    int mid = (left + right) / 2;

    int leftSide = minValue(node * 2, left, mid, start, end);
    int rightSide = minValue(node * 2 + 1, mid+1, right, start, end);

    if (leftSide == -1) return rightSide;
    if (rightSide == -1) return leftSide;
    return min(leftSide,rightSide);
}
int maxValue(int node, int left, int right, int start, int end)
{
    // 범위 안에 없는 경우.
    if (end < left || start > right)
        return -1;
    //  범위 안에 있는 경우
    if (left >= start && right <= end)
        return maxTree[node];

    int mid = (left + right) / 2;

    int leftSide = maxValue(node * 2, left, mid, start, end);
    int rightSide = maxValue(node * 2 + 1, mid+1, right, start, end);

    if (leftSide == -1) return rightSide;
    if (rightSide == -1) return leftSide;
    return max(leftSide,rightSide);
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin >> N >> M;
    numbers = vector<int>(N + 1);

    // segment tree setting
    int tree_height = ceil(log2(N));
    long long tree_size = (1 << (tree_height + 1));
    minTree.resize(tree_size);
    maxTree.resize(tree_size);

    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    setTree(1,0,N-1);
    for (int i = 0; i < M; i++)
    {
        int left, right;
        cin >> left >> right;
        cout << minValue(1, 1, N, left, right) << " " << maxValue(1, 1, N, left, right) << "\n";
    }
    return 0;
}