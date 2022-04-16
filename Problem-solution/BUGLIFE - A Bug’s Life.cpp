/*
 Problem link : https://www.spoj.com/problems/BUGLIFE/

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

const int mx=2e3+123;
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
    ll t;
    cin>>t;
    for(ll test=1;test<=t;test++)
    {
        memset(vis,0,sizeof(vis));
        memset(col,0,sizeof(col));
        ll n,m;
        cin>>n>>m;
    for(ll i=1;i<=n;i++)v[i].clear();
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
    cout<<"Scenario #"<<test<<":"<<endl;
    if(f)cout<<"No suspicious bugs found!"<<endl;
    else cout<<"Suspicious bugs found!"<<endl;

    }

}

//Alhamdulillah..


/*
2
3 3
1 2
2 3
1 3
4 2
1 2
3 4

Output:

Scenario #1:
Suspicious bugs found!
Scenario #2:
No suspicious bugs found!

*/





