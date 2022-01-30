#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int K,N;
vector<int> numbers;
pair<int,int> chk;
void Choose(int count)
{
    if(count>=N)
    {
        for(int i=0;i<numbers.size();i++)
        {
            cout<<numbers[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=1;i<=K;i++)
    {
        if(chk.first==i)
        {
            if(chk.second<2)
            {
                numbers.push_back(i);
                chk.first=i;
                chk.second++;
                Choose(count+1);
                numbers.pop_back();
                chk.second--;
            }
        }
        else
        {
            numbers.push_back(i);
            int temp=chk.first;
            int tempCount=chk.second;
            chk.first=i;
            chk.second=1;
            Choose(count+1);
            numbers.pop_back();
            chk.second=tempCount;
            chk.first=temp;
        }
       
    }

}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>K>>N;
    chk=make_pair(0,0);
    Choose(0);
    return 0;
}