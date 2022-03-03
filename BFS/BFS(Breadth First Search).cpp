/*
 Problem :

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

const int mx=10000;
vector<ll>v[mx];
ll lev[mx];
void bfs(ll source)
{
    memset(lev,-1,sizeof(lev));
    lev[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        ll p=q.front();
        q.pop();
        for( auto x : v[p])
        {
            if(lev[x]==-1)
            {
                lev[x]=lev[p]+1;
                q.push(x);
            }

        }
    }
}
int main()
{
    optimize();
    ll n;
    cin>>n;
    for(ll i=1; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
     for(ll i=1; i<=n; i++)
    {
        cout<<lev[i]<<" ";

     }

}

//Alhamdulillah..


/*
Input:
5
1 2
1 3
2 4
2 5


Output:
0 1 1 2 2

*/




