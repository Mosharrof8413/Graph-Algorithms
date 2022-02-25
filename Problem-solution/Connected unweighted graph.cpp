/*
 Problem : You will be given a connected unweighted graph consisting of n nodes and m undirected edges.
         For each 1 <= i <= n you have to print all adjacent nodes of i.

  Input :
  First line you will be given 2 integers 1 <= n <= 10^5 and 1 <= m <= 2*10^5.
  Then in the next m line of input you will be given two integers u and v where u and v both directly connected by an undirected edge.
  Here 1 <= u, v <= n.

  Output :
  Output will consist of n lines. In the i-th line,
  print all adjacent nodes of the i-th node separated by a single space in any order.

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

vector<ll>v[10000];
ll vis[10000];
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
    for(ll i=1; i<=n; i++)
    {
        for(auto x : v[i])cout<<x<<" ";
        cout<<endl;
    }

}

//Alhamdulillah..


/*
Input:
5 4
1 2
2 3
2 5
5 4


Output:
2
1 3 5
2
5
4 2


*/




