#include<bits/stdc++.h>
using namespace std;

int shortdistance(vector<vector<char>>& mat) {
    int n=mat.size();
    int m=mat[0].size();

    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

    queue<pair<pair<int,int>,int>> q;
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='s'){
                q.push({{i,j},0});
                vis[i][j]=true;
                break;
            }
        }
    }


    while(!q.empty()) {
        auto node=q.front(); q.pop();
        int x=node.first.first;
        int y=node.first.second;
        int distance=node.second;

        if(mat[x][y]=='d') return distance;

        for(int z=0;z<4;z++) {
            int newx=x+dirs[z][0];
            int newy=y+dirs[z][1];

            if(newx>=0&&newx<n && newy>=0&&newy<m && mat[newx][newy]!='0' && !vis[newx][newy]) { //=='*' (d push hi nhi hua....aur upar check krna h 'd')
                q.push({{newx,newy},distance+1});
                vis[newx][newy]=true;
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<char>> mat={
        {'0', '*', '0', 's'},
        {'*', '*', '*', '*'},
        {'0', '*', '0', '*'},
        {'*', 'd', '*', '*'}
    };

    cout<<shortdistance(mat)<<endl;
}