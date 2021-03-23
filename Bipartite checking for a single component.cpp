
//Bipartite graph checking...
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define vi vector<ll>
#define endl '\n'
#define INF 1000000000

vi ar[10001];   //adjacency list....
ll vis[10001];  //visited array...
ll color[2001];
 bool dfs(ll source,ll c)
 {
     vis[source]=1;
     color[source]=c;
     for(ll i=0;i<ar[source].size();i++)
     {
         ll child=ar[source][i];
         if(!vis[child])
         {
            bool res=dfs(child,c^1);
            if(res==false)
                return false;
         }
         else
            if(color[source]==color[child])
            return false;
     }
     return true;
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
    if(dfs(1,0)==true)cout<<"The graph is bipartite"<<endl;
    else cout<<"The graph is not bipartite"<<endl;

}
//Alhamdulillah...
