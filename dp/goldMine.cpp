class Solution {
  public:
    int t[501][501];
    // int maxi=INT_MIN;
    // int dirs[3][2]={{-1,1},{1,1},{0,1}};
  
    int solve(int i, int j, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        if(i<0 || i>=n || j>=m) return 0;
        if(j==m-1) return mat[i][j];
        if(t[i][j]!=-1) return t[i][j];
        
        int sum=mat[i][j] + max(solve(i-1,j+1,mat), max(solve(i+1,j+1,mat),solve(i,j+1,mat)));
        // maxi=max(maxi,sum);
        return t[i][j]=sum;
    }
  
    int maxGold(vector<vector<int>>& mat) {
        memset(t,-1,sizeof(t));
        int n=mat.size();
        int m=mat[0].size();
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++) {
            maxi=max(maxi,solve(i,0,mat));
        }
        return maxi;
    }
};