#include<bits/stdc++.h>
using namespace std;

int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

	void longestPath(int i, int j, int x, int y, int &maxlen,int len, vector<vector<int>> const &mat,vector<vector<int>>& vis) {
		int n=mat.size();
		int m=mat[0].size();
		
		if(i==x && j==y) {
			maxlen=max(maxlen,len);
			return; 
		}   
		
		vis[i][j]=1;
		
		for(int z=0;z<4;z++) {
			int newi=i+dirs[z][0];
			int newj=j+dirs[z][1];
			
			if(newi>=0&&newi<n && newj>=0&&newj<m && !vis[newi][newj] && mat[newi][newj]==1) {
				longestPath(newi,newj,x,y,maxlen,1+len,mat,vis);
				// vis[newi][newj]=0;
			}
		}

		vis[i][j]=0;
 	}

	int findLongestPathLen(vector<vector<int>> const &mat, pair<int,int> const &src, pair<int,int> const &dest)
	{
		int n=mat.size();
		int m=mat[0].size();
		
		int i=src.first;
		int j=src.second;
		int x=dest.first;
		int y=dest.second;
		
		vector<vector<int>> vis(n,vector<int>(m,0));
		
		int maxlen=INT_MIN;
		longestPath(i,j,x,y,maxlen,0,mat,vis);
		return maxlen==INT_MIN ? 0 : maxlen;
	}

int main() {
    vector<vector<int>> mat =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }
    };
 
    // (0, 0) are the source cell, and (5, 7) are the destination cell coordinates
    pair<int, int> src = make_pair(0,0);
    pair<int, int> dest = make_pair(5,7);
 
    cout << "The Maximum length path is " << findLongestPathLen(mat, src, dest)<<'\n';
 
    return 0;
}

/*    {
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    	{1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
	    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
	    {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},      9,8
	    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},      0,0
	    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	    {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},
	    {1, 0, 1, 1, 1, 1, 0, 0, 1, 1},
	    {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
	    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}
    }
*/