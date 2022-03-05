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

const int mx=100123;
vector<ll>v[mx];
ll col[mx];

bool bfs(ll s)
{
    memset(col,-1,sizeof(col));
    col[s]=1;
    queue<ll>q;
    q.push(s);
    bool f=true;
    while(!q.empty() )
    {
        ll p=q.front();
        q.pop();
        for(auto x : v[p] )
        {
            if(col[x]==-1)
            {
                if(col[p]==1)
                    col[x]=2;
                else col[x]=1;

                q.push(x);
            }
            else if(col[x]==col[p])return 0;
        }

    }
    return 1;
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
    if(bfs(1))cout<<"The graph is Bipartite"<<endl;
    else cout<<"The graph is not bipartite"<<endl;


}

//Alhamdulillah..


/*
Input:
4 4
1 2
2 3
3 4
4 1


Output:

The graph is Bipartite

*/





