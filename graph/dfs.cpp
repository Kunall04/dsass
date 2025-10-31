class Solution {
  public:
    void solve(int node, vector<vector<int>>& adj, vector<int>& list,vector<int>& vis) {
        vis[node]=1;
        list.push_back(node);
        
        for(auto it: adj[node]) {
            if(!vis[it]) {
                vis[it]=1;
                solve(it,adj,list,vis);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> vis(n,0);
        vector<int> list;
        solve(0,adj,list,vis);
        return list;
    }
};