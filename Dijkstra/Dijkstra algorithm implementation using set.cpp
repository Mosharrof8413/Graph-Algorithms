//Problem link : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
//Function to find the shortest distance of all the vertices
//from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
// Code here
        set<pair<int,int> >st;
        st.insert({0,S});

        vector<int>dis(V,1e9);
        dis[S]=0;

        while(!st.empty())
        {
            auto it=*(st.begin());
            int node=it.second;
            int distance=it.first;
            st.erase(it);

            for(auto it : adj[node])
            {
                int adjNode=it[0];
                int edgeW=it[1];
                if(distance+edgeW<dis[adjNode])
                {
                    if(dis[adjNode]!=1e9)
                    {
                        st.erase({dis[adjNode],adjNode});
                    }
                    dis[adjNode]=distance + edgeW;
                    st.insert({dis[adjNode],adjNode});
                }
            }
        }
        return dis;
    }
};
//Alhamdulillah…
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for(int i=0; i<V; i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }

    return 0;
}
/*
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
*/

