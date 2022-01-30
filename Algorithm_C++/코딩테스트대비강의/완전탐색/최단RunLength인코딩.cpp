#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

string input;
int min_length=987654321;
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>input;
    int size=input.size();
    for(int i=0;i<size;i++)
    {
        char shiftChar=input[size-1];
        int count=1; // 다른 문자 수
        //shift 작업
        for(int j=input.size();j>0;j--)
        {
            input[j]=input[j-1];
        }
        input[0]=shiftChar;

        // encoding 작업
        char cmp_c=input[0];
        for(int i=1;i<input.size();i++)
        {
            //다른 문자 만나는 경우
            if(input[i]!=cmp_c)
            {        
                count++;  
                cmp_c=input[i];
            }
        }
         int cmp_length=(count * 2);
        if(count==1 && size==10)
        {
            min_length=3;
        }
        else
        {
            min_length=min(min_length,cmp_length);
        }
    }
    cout<<min_length<<"\n";

    return 0;
}