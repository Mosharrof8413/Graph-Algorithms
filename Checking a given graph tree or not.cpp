
//checking a graph is tree or not..
//A graph will be tree if it full fill the 3 requried conditions...
//    1.the numbers of nodes-1 ==edges;
//    2.connected components will be one(1);
//    3.there will be no cycle in the whole graph...
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mk make_pair
#define vi vector<ll>
#define endl '\n'
#define INF 1000000000

vi ar[10001];   //adjacency list....
ll vis[10001];

 void dfs(ll source)
 {
     vis[source]=1;
     for(ll i=0;i<ar[source].size();i++)
     {
         ll child=ar[source][i];
         if(!vis[child])
         {
             dfs(child);
         }
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
    ll cnt=0;
    for(ll i=1;i<=nodes;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;          //counting connected component in a graph...
        }
    }
    if(cnt==1 && nodes==edges+1)
     cout<<"YES,the given graph is a tree"<<endl;
     else cout<<"NO,the given graph is not a tree"<<endl;

}

//Alhamdulillah...
