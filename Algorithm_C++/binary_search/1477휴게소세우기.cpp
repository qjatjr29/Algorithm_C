#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int N,M,L;
vector<int> distances;
int result;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>L;
    // 처음 시작점.
    distances.push_back(0);
    for(int i=0;i<N;i++)
    {
        int number;
        cin>>number;
        distances.push_back(number);
    }
    // 고속도로 마지막.
    distances.push_back(L); 
    sort(distances.begin(),distances.end());
    int left=1;
    int right=L-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        int restCount=0;
        for(int i=1;i<distances.size();i++)
        {
            int section=distances[i]-distances[i-1];
            if(section/mid >0)
            {
                restCount+= (section/mid);
                if(section%mid==0) restCount--;
            }
        }
        // 들어갈 수 있는 휴게소 가 많은 경우
        // 휴게소 마다 거리를 더 크게 만든다.
        if(restCount>M)
        {
            left=mid+1;
        }
        // 들어갈 휴게소가 적은 경우
        // 휴게소 마다 거리를 더 작게 만든다.
        else 
        {
            result=mid;
            right=mid-1;
        }
    }

    cout<<result<<"\n";
    return 0;
}