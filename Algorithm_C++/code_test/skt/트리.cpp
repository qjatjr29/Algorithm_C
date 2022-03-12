#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>
#include <queue>

using namespace std;
vector<vector<long long> > distances;
vector<int> dp;
long long answer = 0;
void calcAnswer(int index,int cnt,int n)
{
    if(cnt==3)
    {
        
        for(int i=0;i<3;i++)
        {
            int first = dp[i];
            int second = dp[(i+1)%3];
            int third = dp[(i+2)%3];
            if(distances[first][second] + distances[second][third] == distances[first][third]) answer++;
            if(distances[first][third] + distances[third][second] == distances[first][second]) answer++;
        }

       return;
    }
    for(int i=index+1;i<=n;i++)
    {
        dp.push_back(i);
        calcAnswer(i,cnt+1,n);
        dp.pop_back();
    }

}
long long solution(int n, vector<vector<int> > edges) {

    distances = vector<vector<long long> >(n+1,vector<long long>(n+1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == j) continue;
            distances[i][j] = 987654321;
        }
    }

    for(int i=0;i<edges.size();i++)
    {
        int start = edges[i][0];
        int end = edges[i][1];
        // cout<<start<<" "<<end<<"\n";
        distances[start][end] = 1;
        distances[end][start] = 1;
    }

    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                distances[j][i] = min(distances[j][i],distances[j][k]+distances[k][i]);
            }
        }
    }
    // for(int j=0;j<n;j++)
    //     {
    //         for(int k=0;k<n;k++)
    //         {
    //             cout<<distances[j][k]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    
    calcAnswer(-1,0,n-1);


    return answer;
}
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<vector<int> > edge;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(1);
    edge.push_back(temp);
    // temp.clear();

    // temp.push_back(0);
    // temp.push_back(2);
    // edge.push_back(temp);
    // temp.clear();

    // temp.push_back(1);
    // temp.push_back(3);
    // edge.push_back(temp);
    // temp.clear();

    // temp.push_back(1);
    // temp.push_back(4);
    // edge.push_back(temp);
    // temp.clear();
    
   // solution(5,edge);

    return 0;
}