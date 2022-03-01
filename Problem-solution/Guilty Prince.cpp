/*
 Problem : https://lightoj.com/problem/guilty-prince

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

const int mx=50;
char v[mx][mx];
int vis[mx][mx];
ll m,n,cnt=0;
ll dx[]= {+1,-1,0,0}; //direction array...
ll dy[]= {0,0,+1,-1};
void dfs(ll x,ll y)
{
    vis[x][y]=1;
    cnt++;
    for(ll i=0; i<4; i++)
    {
        ll x1=x+dx[i];
        ll y1=y+dy[i];
        if(x1>=1 && x1<=n && y1>=1 && y1<=m && !vis[x1][y1] && v[x1][y1]!='#')
        {
            dfs(x1,y1);
        }
    }
}

int main()
{
    optimize();
    ll t;
    cin>>t;
    for(ll tc=1; tc<=t; tc++)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        cin>>m>>n;
        ll x,y;
        for(ll i=1; i<=n; i++)
        {
            for(ll j=1; j<=m; j++)
            {
                cin>>v[i][j];
                if(v[i][j]=='@')x=i,y=j;
            }
        }

        dfs(x,y);
        cout<<"Case "<<tc<<": "<<cnt<<endl;
    }

}

//Alhamdulillah..


/*
Input:
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..

Output:
Case 1: 45
Case 2: 59
Case 3: 6
Case 4: 13


*/




