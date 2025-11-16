#include <bits/stdc++.h>
using namespace std;

int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int i, int j, int x, int y, int &cnt, vector<vector<int>> const &maze, vector<vector<int>> &vis) {
    int n = maze.size();

    if(i == x && j == y) {
        cnt++;
        return;
    }

    vis[i][j] = 1;

    for(int k=0; k<4; k++) {
        int ni = i + dirs[k][0];
        int nj = j + dirs[k][1];

        if(ni>=0 && ni<n && nj>=0 && nj<n && maze[ni][nj]==1 && !vis[ni][nj])
            dfs(ni, nj, x, y, cnt, maze, vis);
    }

    vis[i][j] = 0;
}

int findCount(vector<vector<int>> const &maze, pair<int,int> src, pair<int,int> dest){
    int n = maze.size();
    if(n==0) return 0;

    int i = src.first,  j = src.second;
    int x = dest.first, y = dest.second;

    if(i<0||i>=n||j<0||j>=n) return 0;
    if(x<0||x>=n||y<0||y>=n) return 0;
    if(maze[i][j]==0 || maze[x][y]==0) return 0;

    vector<vector<int>> vis(n, vector<int>(n,0));

    int cnt = 0;
    dfs(i, j, x, y, cnt, maze, vis);
    return cnt;
}

int main()
{
    vector<vector<int>> maze = {
        {1,1,1,1},
        {1,1,0,1},
        {0,1,0,1},
        {1,1,1,1}
    };

    pair<int,int> src = {0,0};
    pair<int,int> dest = {3,3};

    cout << findCount(maze, src, dest) << "\n";
    return 0;
}
