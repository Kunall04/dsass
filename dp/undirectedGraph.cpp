class Solution {
  public:
    bool solve(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,-1});
        
        while(!q.empty()) {
            auto it=q.front(); q.pop();
            int curr=it.first;
            int parent=it.second;
            
            for(auto nd: adj[curr]) {
                if(!vis[nd]) {
                    vis[nd]=1;
                    q.push({nd,curr});
                }
                else if(nd!=parent) return true;
                //the node is visited and its not the parent(from which the 0rg node came))
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        int n=edges.size();
        
        vector<int> vis(V,0);
        vector<vector<int>> adj(V);
        
        for(int i=0;i<n;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        
        for(int i=0;i<V;i++) {
            if(!vis[i])
                if(solve(i, vis, adj)) return true;
        }
        return false;
    }
};