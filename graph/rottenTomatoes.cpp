class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), cnt=0;
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==2)
                    q.push({{i,j},cnt});
            }
        }

        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        int mini=0;

        while(!q.empty()) {
            auto it=q.front(); q.pop();
            int row=it.first.first;
            int col=it.first.second;
            int no=it.second;

            for(int i=0;i<4;i++) {
                int x=row+dir[i][0];
                int y=col+dir[i][1];

                if(x>=0&&x<n && y>=0&&y<m && grid[x][y]==1) {
                    grid[x][y]=2;
                    q.push({{x,y},no+1});
                }
            }
            mini=no;

        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]==1)
                return -1;
            }
        }

        return mini;
    }
};