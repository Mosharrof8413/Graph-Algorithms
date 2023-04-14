//Problem Link :https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >dis(n,vector<int>(m,1e9));

        dis[source.first][source.second]=0;
        queue<pair<int,pair<int,int> > >q;
        q.push({0,{source.first,source.second}});

        int delrow[]= {-1,0,1,0};
        int delcol[]= {0,1,0,-1};

        while(!q.empty())
        {
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            for(int i=0; i<4; i++)
            {
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && distance+1<dis[nrow][ncol]) //Dijkstra
                {
                    dis[nrow][ncol]=distance+1;
                    if(nrow==destination.first && ncol==destination.second)return dis[nrow][ncol];
                    q.push({distance+1,{nrow,ncol}});
                }
            }
        }
        //if(dis[destination.first][destination.second]==1e9)return -1;
        //return dis[destination.first][destination.second];
        return -1;
    }
};
//Alhamdulillah...


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}
/*
input :
4 4
1 1 1 1
0 0 0 1
0 0 0 1
0 0 0 1
0 0
3 3
output :
6
*/

