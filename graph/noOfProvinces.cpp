class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>&vis) {
        vis[node]=1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                vis[it]=1;
                dfs(it,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size(), cnt=0;
        vector<int>vis(n,0);
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(arr[i][j]==1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }


        for(int i=0;i<n;i++) {
            if(!vis[i]){
                cnt++; dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};