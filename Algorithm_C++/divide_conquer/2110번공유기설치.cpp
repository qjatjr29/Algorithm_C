#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int N, C;
vector<long long> houses;
long long answer;
int internetModem(int distance)
{
    int curHouse = houses[0];
    int count = 1;      
    for(int i=1;i<N;i++)
    {
        if(houses[i] - curHouse >= distance)
        {
            count ++ ;
            curHouse = houses[i];
        }
    }
    return count;
}
void find()
{
    // 공유기 간 간격의 최소, 최대값
    long long low = 1;
    long long high = houses[N - 1] - houses[0] +1;
   
    while(low < high)
    {
        int mid = (low+high)/2;

        if(internetModem(mid) < C)
        {
            high = mid;
        }
        else
        {
            answer = mid;
            low = mid+1;
        }

    }
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N >> C;

    for (int i = 0; i < N; i++)
    {
        long long house;
        cin >> house;
        houses.push_back(house);
    }
    sort(houses.begin(), houses.end());
    find();
    cout << answer << "\n";

    return 0;
}