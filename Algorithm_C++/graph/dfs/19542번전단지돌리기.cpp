#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

int N,S,D;
vector<vector<int> > adj;
vector<int> depth;
int answer;
int maxDepth;

int poster(int here)
{
   int ans = depth[here];
   for(int i=0;i<adj[here].size();i++)
   {
       int next = adj[here][i];
       if(depth[next] == 0)
       {
           depth[next] = depth[here]+1;
           ans = max(ans,poster(next));
       }
   }
   if(ans - depth[here] >=D) answer+=2;
   return ans;
}                                                                                                                                                                                                                                                                                                                                                                                   
int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>S>>D;
    adj = vector<vector<int> >(N+1,vector<int>());
    depth = vector<int>(N+1,0);
    for(int i=0;i<N-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    depth[S] = 1;
    poster(S);
    if(answer - 2 >=0) cout<<answer-2<<"\n";
    else cout<<"0 "<<"\n"; 
    return 0;
}