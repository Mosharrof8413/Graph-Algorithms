/*
 Problem : https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/

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

const int mx=1123;
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

        ll n;
        cin>>n;
        n--;
        while(n--)
        {
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);

        }
        bfs(1);
        ll q;
        cin>>q;
        ll mn=100000,ans=100000;
        for(ll i=0;i<q;i++)
        {
            ll x;
            cin>>x;
            if(lev[x]<=mn)
            {
                ans=min(ans,x);
                mn=lev[x];
            }

        }
        cout<<ans<<endl;
    }

//Alhamdulillah..


/*
Input:
6
1 2
1 3
1 4
2 5
2 6
4
5
6
3
4

Output:
3


*/






