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


vector<ll>v[10005];
ll vis[10005];
void dfs(ll node)
{
    vis[node]=1;
    for(auto child : v[node])
    {
        if(vis[child]==0)dfs(child);
        //vis[child]==1 continue ....
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
   ll cnt=0;
   for(ll i=1;i<=node;i++)
   {
       if(vis[i]==0)
       {
           cnt++;
           dfs(i);
       }
   }
   cout<<cnt<<endl;

}

//Alhamdulillah..


/*
Input:
10 6
1 2
1 3
3 4
3 5
6 7
6 8

Output:
4

*/




