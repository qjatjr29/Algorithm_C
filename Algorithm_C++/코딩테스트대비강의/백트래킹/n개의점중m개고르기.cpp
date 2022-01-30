#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

vector<pair<int,int> > point;
vector<int> choosePoint;
int n,m;
double ans=987654321;
double calcPath(int x,int y,int cmpx,int cmpy)
{ 
    double dist=pow((x - cmpx),2) + pow((y - cmpy),2);
    return pow(dist,0.5);
}
void Choose(int count,int preNum)
{
    if(count==m)
    {
        double temp=0;
        for(int i=0;i<choosePoint.size();i++)
        {
            int x=point[choosePoint[i]].first;
            int y=point[choosePoint[i]].second;
            for(int j=i+1;j<choosePoint.size();j++)
            {
                int nx=point[choosePoint[j]].first;
                int ny=point[choosePoint[j]].second;
                temp=max(temp,calcPath(x,y,nx,ny));
            }
        }
        ans=min(ans,temp);
        return;
    }
    for(int i=preNum+1;i<n;i++)
    {
        choosePoint.push_back(i);
        Choose(count+1,i);
        choosePoint.pop_back();
    }
}

int main()
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        point.push_back(make_pair(x,y));
    }
    //sort(point.begin(),point.end());
    Choose(0,-1);
    cout<<pow(ans,2)<<"\n";
    return 0;
}