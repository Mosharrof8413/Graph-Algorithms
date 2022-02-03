

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

vector<ll>v[1000];
ll vis[1000],dis[1000];
void dfs(ll node,ll d)
{
    vis[node]=1;
    dis[node]=d;
    for(auto child : v[node])
    {
        if(vis[child]==0)
            dfs(child,d+1);
    }
}
int main()
{
    optimize();
    ll node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        ll x,y;
        cin>>x>>y;
        v[x].PB(y);
        v[y].PB(x);
    }
    ll source;
    cin>>source;
    dfs(source,0);
    for(ll i=1;i<=node;i++)
    {
        cout<<source<<" to "<< i<<" distance ->"<<dis[i]<<endl;
    }
}

//Alhamdulillah..


/*
Input:
6 5
1 2
1 3
3 4
4 5
5 6
1


Output:
1 to 1 distance ->0
1 to 2 distance ->1
1 to 3 distance ->1
1 to 4 distance ->2
1 to 5 distance ->3
1 to 6 distance ->4
*/




