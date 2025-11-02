class Solution {
public:
    int t[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int i, int j,vector<vector<int>>& adj, int color, int oldc) {
        int n=adj.size();
        int m=adj[0].size();
        adj[i][j]=color;

        for(int z=0;z<4;z++) {
            int x=i+t[z][0];
            int y=j+t[z][1];
            if(x>=0 && x<n && y>=0 && y<m && adj[x][y]==oldc) {
                    // vis[x][y]=1;
                    dfs(x,y,adj,color,oldc);
                }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        // int n=img.size();
        // int m=img[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        if(img[sr][sc]==color) return img;

        dfs(sr, sc, img,color,img[sr][sc]);

        return img;
    }
};