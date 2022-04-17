/*
 Problem : cycle checking in multiple components...

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

const int mx=1e5+1123;
vector<ll>adj[mx];
ll vis[mx];

bool isCycle(ll node, ll par)
{
    vis[node]=1;
    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            if(isCycle(child,node))
                return true;
        }
        else
        {
            if(child != par)
                return true;
        }

    }
    return false;
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
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool ans=false;
    for(ll i=1;i<=n;i++)
    {
    //if(isCycle(1,-1))cout<<"There is present cycle"<<endl;    //cycle checking for a single component..
    //else cout<<"There is no present any cycle"<<endl;
    if(!vis[i])
    {
        if(isCycle(i,-1))ans=true;
    }
    }
    if(ans)cout<<"There is present cycle"<<endl;
    else cout<<"There is no present any cycle"<<endl;
}

//Alhamdulillah..


/*

input:

6 5
1 2
1 3
4 5
5 6
6 4

Output:

There is present cycle


*/




