

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

vector<ll>v[10000];
ll vis[1000],dis[10000];
void dfs(ll node,ll d)
{
    vis[node]=1;
    dis[node]=d;
    for(auto child : v[node])
    {
        if(vis[child]==0)dfs(child,d+1);
    }
}
int main()
{
    optimize();
   ll n;
   cin>>n;
   n--;
   while(n--)
   {
       ll x,y;
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
   }
   dfs(1,0);
   ll q;
   cin>>q;
   ll mn=100000000;
   ll ans=0;
   for(ll i=0;i<q;i++)
   {
       ll w;
       cin>>w;
       if(dis[w]<mn)
       {
           mn=dis[w];
           ans=w;
       }
       else if(dis[w]==mn)ans=min(ans,w);
   }
   cout<<ans<<endl;


}

//Alhamdulillah..


/*
Input:
6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4

Output:
3

*/




