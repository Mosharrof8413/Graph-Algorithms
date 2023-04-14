//Problem Link :https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int,int>>adj[n+2];
        for(auto it : edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        vector<int>dis(n+1,1e9),parent(n+1);  //1 based array
        for(int i=1;i<=n;i++)parent[i]=i;

        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        dis[1]=0;
        pq.push({0,1});
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            int node=it.second;
            int distance=it.first;

            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int weight = it.second;

                if(distance + weight < dis[adjNode])
                {
                    dis[adjNode]=distance + weight;
                    pq.push({distance+weight,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        vector<int>ans;
        if(dis[n]==1e9)return {-1};
        int node=n;
        while(parent[node]!=node)
        {
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1); //source

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//Alhamdulillah...
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

/*
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
1 4 3 5
*/

