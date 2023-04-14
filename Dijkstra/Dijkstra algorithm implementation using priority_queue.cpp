//Problem Link : https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
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
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
        vector<int>dist(V);
        for(int i=0;i<V;i++)dist[i]=1e9;

        dist[S]=0;
        pq.push({0,S}); //distance and node

        while(!pq.empty())
        {
           int dis=pq.top().first;
           int node=pq.top().second;
           pq.pop();

           for(auto it : adj[node])
           {
               int adjNode=it[0];
               int edgeWeight=it[1];
               if(dis+edgeWeight<dist[adjNode])
               {
                   dist[adjNode]=dis+edgeWeight;
                   pq.push({dist[adjNode],adjNode});
               }
           }
        }
        return dist;
    }
};
//Alhamdulillah…
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
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
