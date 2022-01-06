#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N,M,K;
long long section[1000001]; // array
vector<long long> segmentTree;  // segment tree
long long result;
long long make_segmentTree(int Node,int Start,int End){
    if(Start==End)return segmentTree[Node]=section[Start];


    int mid=(Start+End) /2;
    long long left=make_segmentTree(Node*2,Start,mid);
    long long right=make_segmentTree(Node*2+1,mid+1,End);
    segmentTree[Node]=left+right;
    return segmentTree[Node];
}

long long sum_segmentTree(int node,int start,int end,int left,int right)
{
    // 범위 밖에 있는 경우
    if(left>end || right <start )return 0;
    // 범위에 속해 있는 경우
    if(left<=start && end <= right)
    {
        return segmentTree[node];
    }   
    // 범위에 겹쳐 있는 경우 
    // 왼쪽, 오른쪽 경우 들어간다.
    int mid=(start+end)/2;
    long long left_value=sum_segmentTree(node*2,start,mid,left,right);
    long long right_value=sum_segmentTree(node*2+1,mid+1,end,left,right);

    return left_value+right_value;
}
void Update_segmentTree(int node,int start,int end,int index,long long value)
{
    // 범위에 없는 경우
    if(index<start || index>end)return;

    segmentTree[node]+=value;
    // 범위에 속하는 경우
    if(start==end)
    {
       return;
    }
    int mid=(start+end)/2;
    Update_segmentTree(node*2,start,mid,index,value);
    Update_segmentTree(node*2+1,mid+1,end,index,value);
}
int main()
{
    //input
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>N>>M>>K;
    
    for(int i=0;i<N;i++)
    {
        int number;
        cin>>number;
        section[i]=number;
    }

    // segment tree setting
    int tree_height=ceil(log2(N));
    long long tree_size=(1<<(tree_height+1));
    segmentTree.resize(tree_size);

    make_segmentTree(1,0,N-1);
 
    // implement
    for(int i=0;i<M+K;i++)
    {
        int cmd,index;
        long long value;
        cin>>cmd>>index>>value;
        long long gap;
        if(cmd==1)
        {
            gap=value-section[index-1];
            section[index-1]=value;
            Update_segmentTree(1,0,N-1,index-1,gap);
        }
        else
        {
            result=sum_segmentTree(1,0,N-1,index-1,value-1);
            cout<<result<<"\n";
        }
       
     
    }
    return 0;
}

