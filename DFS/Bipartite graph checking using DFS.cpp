/*
 Problem link :Bipartite graph checking for multiple components...

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

const int mx=1e5+123;
vector<ll>v[mx];
ll vis[mx];
ll col[mx];
bool dfs(ll node,ll c)
{
    vis[node]=1;
    col[node]=c;
    for(auto child : v[node] )
    {
        if(!vis[child])
        {
            bool ans=dfs(child,c^1);
            if(!ans)return false;
        }
        else
        {
            if(col[child]==col[node])return false;
        }
    }
    return true;
}

int main()
{
    optimize();

    ll n,m;
    cin>>n>>m;
    while(m--)
    {
        ll x,y;
        cin>>x>>y;
        v[x].PB(y);
        v[y].PB(x);
    }
    bool f=true;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
             f=dfs(i,1);
            if(!f) break;
        }
    }

    if(f)cout<<"The graph is Bipartite"<<endl;
    else cout<<"The graph is not Bipartite"<<endl;

}

//Alhamdulillah..


/*
8 5
1 2
2 3
2 4
3 5
6 7

Output:

The graph is Bipartite

*/




