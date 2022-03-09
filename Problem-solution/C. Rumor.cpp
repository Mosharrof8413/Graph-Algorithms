/*
 Problem : https://codeforces.com/problemset/problem/893/C

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

const int mx=100123;
vector<int>adj[mx];
ll vis[mx],cost[mx];

ll dfs(ll node)
{
    vis[node]=1;
    ll mn=cost[node];
    for(auto child : adj[node] )
    {

        if(!vis[child])
          mn=min(mn,dfs(child));

    }
    return mn;

}

int main()
{
    optimize();
    ll n,m;
    cin>>n>>m;

    for(ll i=1; i<=n; i++) cin>>cost[i];
    for(ll i=0; i<m; i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            ans+=dfs(i);
        }

    }
    cout<<ans<<endl;



}

//Alhamdulillah..


/*
10 5
1 6 2 7 3 8 4 9 5 10
1 2
3 4
5 6
7 8
9 10

Output:
15
*/


