class Solution {
  public:
    void topo(int node, stack<int>& st, vector<int>& vis, vector<pair<int,int>> adj[]) {
        vis[node]=1;
        
        for(auto it: adj[node]) {
            int v=it.first;
            if(!vis[v]) topo(v,st,vis,adj);
        }
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& m) {
        vector<int> vis(V,0);
        stack<int> st;
        
        vector<pair<int,int>> adj[V];
        for(int i=0;i<E;i++) {
            int u=m[i][0];
            int v=m[i][1];
            int w=m[i][2];
            
            adj[u].push_back({v,w});
        }
        
        for(int i=0;i<V;i++) {
            if(!vis[i]) topo(i,st,vis,adj);
        }
        
        vector<int> dist(V,1e9);
        // dist[0]=0;
        dist[0]=0;
        
        while(!st.empty()) {
            int node=st.top(); st.pop();
            
            if (dist[node]!=1e9) {
                for(auto it: adj[node]) {
                    int vert=it.first;
                    int d=it.second;
                    
                    dist[vert]=min(dist[vert],d+dist[node]);
                }
            }
        }
        
        for (int i=0;i<V;i+)
            if(dist[i]==1e9) dist[i]=-1;
        return dist;
    }
};
