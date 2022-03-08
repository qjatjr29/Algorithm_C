#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N; // 수 3개가 추가되는 횟수
int a,b; // 처음 두 개의 수.
vector<int> numbers;
int answer[2];
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>a>>b;
    cin>>N;
    numbers.push_back(a);
    numbers.push_back(b);

    int cnt = 1;
    while(1)
    {
        if(cnt == N+1 )break;
        int addNumber;
        for(int i=0;i<3;i++)
        {
            cin>>addNumber;
            numbers.push_back(addNumber);
        }
        sort(numbers.begin(),numbers.end());

        int index = cnt+1;
        cout<<numbers[index-1]<<" "<<numbers[index*2-1]<<"\n";
        cnt++;
    }
    

    return 0;
}