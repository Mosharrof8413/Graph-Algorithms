

#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

#define endl '\n'
#define PB push_back
#define F first
#define S second

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);


vector<ll>v[1003];
ll vis[1003];
void DFS(ll node)
{
    vis[node]=1;
    cout<<"->"<<node;
    for(ll i=0;i<v[node].size();i++)
    {
        ll child=v[node][i];
        if(vis[child]==0)
        {
            DFS(child);
        }
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
    DFS(1);

}

//Alhamdulillah..


/*
Input:
6 5
1 2
1 3
3 4
3 5
5 6

Output:
->1->2->3->4->5->6

*/



