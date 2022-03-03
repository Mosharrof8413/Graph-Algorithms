/*
 Problem : https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

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

const int mx=10123;
vector<ll>v[mx];
ll lev[mx];

void bfs(int s)
{
    memset(lev,-1,sizeof(lev));
    lev[s]=0;

    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto x : v[u])
        {
            if(lev[x]==-1)
            {
                lev[x]=lev[u]+1;
                q.push(x);
            }
        }
    }
}

int main()
{
    optimize();
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        for(ll i=0;i<mx;i++)v[i].clear();
        ll n,m;
        cin>>n>>m;
        while(m--)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);

        }
        bfs(1);
        cout<<lev[n]<<endl;
    }

}

//Alhamdulillah..


/*
Input:
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2


Output:
2
2


*/





