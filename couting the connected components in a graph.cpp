//Count the counted component in a graph...

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
vector<ll> ar[100001];
ll vis[100001];
 void dfs(ll sourch)
 {
     vis[sourch]=1;
     for(ll i=0;i<ar[sourch].size();i++)
     {
         ll child=ar[sourch][i];
         if(vis[child]==0)
            dfs(child);
     }
 }
int main()
{
    ll nodes,edges,u,v;
    cin>>nodes>>edges;
    for(ll i=1;i<=edges;i++)
    {
        cin>>u>>v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    ll cnt=0;                 //number of connected components....
    for(ll i=1;i<=nodes;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<"The total number of connected components in the given graph is "<<cnt<<endl;
}
// Alhamdullillah...
