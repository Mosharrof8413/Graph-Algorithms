/*
 Problem link : https://codeforces.com/problemset/problem/445/B

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
void dfs(ll node)
{
    vis[node]=1;
    for(auto child : v[node])
    {
        if(!vis[child])dfs(child);
    }
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
    ll cnt=0;
    for(ll i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    ll ans=n-cnt;
    ans=pow(2,ans);
    cout<<ans<<endl;

}

//Alhamdulillah..


/*
3 2
1 2
2 3


Output:
4


*/





