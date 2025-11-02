class Solution {
public:
    int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& adj) {
        int n=adj.size();
        int m=adj[0].size();
        vis[row][col]=1;

        for(int i=0;i<4;i++) { 
                int x=row+ dir[i][0];
                int y=col+ dir[i][1];

                if(x>=0 && x<n && y>=0 && y<m && adj[x][y]=='1' && !vis[x][y]) {
                    // vis[x][y]=1;
                    dfs(x,y,vis,adj);
                }
            }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), cnt=0;
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};