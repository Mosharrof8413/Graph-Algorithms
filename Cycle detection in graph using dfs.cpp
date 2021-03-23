#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define vi vector<ll>
#define endl '\n'
#define INF 1000000000

vi ar[100001];   //adjacency list....
ll vis[100001];
 bool dfs(ll source,ll parent)
 {
     vis[source]=1;
     for(ll i=0;i<ar[source].size();i++)
     {
         ll child=ar[source][i];
         if(!vis[child])
         {
            if(dfs(child,source)==true)
                return true;
         }
         else
            if(child!=parent)
            return true;
     }
     return false;
 }
int main()
{
     ll nodes,edges,u,v;
     cin>>nodes>>edges;

    while(edges--)
    {
        cin>>u>>v;
        ar[u].pb(v);
        ar[v].pb(u);
    }
    if(dfs(1,1)==true)cout<<"Cycle is present in the undirected graph"<<endl;
    else cout<<"Cycle is not present in the undirected graph"<<endl;

}

//Alhamdulillah...

