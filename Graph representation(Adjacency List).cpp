

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
    for(ll i=1;i<=node;i++)
    {
        cout<<i;
        for(ll j=0;j<v[i].size();j++)
        {
            cout<<"->"<<v[i][j];
        }
        cout<<endl;
    }
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
1->2->3
2->1
3->1->4->5
4->3
5->3->6
6->5
*/


