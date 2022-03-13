/*
 Problem : https://codeforces.com/problemset/problem/862/B

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
vector<ll>adj[mx];
ll lev[mx],col[mx];

void bfs(ll s)
{
    memset(lev,-1,sizeof(lev));
    lev[s]=0;
    col[s]=1;
    queue<ll>q;
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
            if(col[u]==1)
            col[v]=2;
            else col[v]=1;

            q.push(v);
            }
        }
    }


}

int main()
{
    optimize();
    ll n;
    cin>>n;
    for(ll i=1;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(1);
    ll one=0,two=0;
     for(ll i=1;i<=n;i++)
    {
        //cout<<col[i]<<" ";
        if(col[i]==1)one++;
        else two++;

     }
    ll ans=one*two;
    ans-=(n-1);   //already collected edges...n-1;
    cout<<ans<<endl;




}

//Alhamdulillah..


/*
Input:
5
1 2
2 3
3 4
4 5


Output:
2

*/





