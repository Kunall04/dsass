class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& arr) {
        int n=arr.size(); int m=arr[0].size();


        if(i<0 || i>=n || j<0 || j>=m || arr[i][j]==0) return 0;
        
        int g=arr[i][j]; //made 0 to not visit the cell again
        arr[i][j]=0;
            int x=solve(i+1,j,arr);
            int y=solve(i-1,j,arr);
            int p=solve(i,j+1,arr);
            int q=solve(i,j-1,arr);

        arr[i][j]=g; //restoreddnigga
        return g+max({x,y,p,q});
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        int maxi=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]!=0)
                    maxi=max(maxi,solve(i,j,grid));
            }
        }
        return maxi;
    }
};