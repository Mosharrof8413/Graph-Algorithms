
/*
 Problem : Printing shortest path using bfs(unweighted graph)

*/

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx=1001;
vector<int>adj[mx];
ll lev[mx];
ll par[mx];
ll vis[mx];

void bfs(ll s)
{
    memset(lev,-1,sizeof(lev));
    lev[s]=0;

    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(auto v : adj[u] )
        {
            if(lev[v]==-1)
            {
                lev[v]=lev[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}

int main()
{
    optimize();
    ll node;
    cin>>node;
    ll edge;
    cin>>edge;
    while(edge--)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll source,destination;
    cin>>source>>destination;
    bfs(source);

    if(lev[s]==-1)
    {
        cout<<"NO route"<<endl;
        return 0;
    }

    vector<ll>path;
    par[source]=-1;
    ll x=destination;
    while(x!=-1)
    {
        path.push_back(x);
        x=par[x];
    }
    reverse(path.begin(),path.end());
    for(auto u : path)cout<<u<<" ";
    cout<<endl;


}

//Alhamdulillah..


/*
Input:
5 4
1 2
1 3
2 4
2 5

3 5


Output:
3 1 2 5

*/
