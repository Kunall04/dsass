class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                // else vis[i][j]=0;
            }
        }

        while(!q.empty()) {
            auto it=q.front();
            int x=it.first.first;
            int y=it.first.second;
            int dist=it.second;
            q.pop();
            dis[x][y]=dist;

            for(int i=0;i<4;i++) {
                int X=x+dirs[i][0];
                int Y=y+dirs[i][1];
                if(X>=0&&X<n && Y>=0&&Y<m && !vis[X][Y]) {
                    vis[X][Y]=1;
                    q.push({{X,Y},dist+1});
                } 
            }
        }
        return dis;
    }
};