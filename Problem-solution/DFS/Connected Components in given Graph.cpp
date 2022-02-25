/*
 Problem link : https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

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
    //cout<<"Connected Components in a graph is : "<<cnt<<endl;
    cout<<cnt<<endl;

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
3

*/




