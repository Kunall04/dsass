#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<string>& board) {
    int r=row;
    int c=col;

    while(row>=0 && col>=0) {
        if(board[row--][col--]=='Q') return false;
    }

    col=c;
    row=r;
    while(col>=0) {
        if(board[row][col--]=='Q') return false;
    }

    row=r;
    col=c;
    while(row<n && col>=0) {
        if(board[row++][col--]=='Q') return false;
    }

    return true;
}

void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans) {
    if(col==n) {
        ans.push_back(board);
        return;
    }

    for(int row=0;row<n;row++) {
        if(isSafe(row,col,n,board)) {
            board[row][col]='Q';
            solve(col+1,n,board,ans);
            board[row][col]='.';
        }
    }
}

vector<vector<string>> nq(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++) board[i]=s;

    solve(0,n,board,ans);

    return ans;
}

int main() {
    int n=4;

    vector<vector<string>> ans=nq(n);

    for(size_t i=0;i<ans.size();i++) {
        for(const string &row: ans[i]) cout<<row<<'\n';
        cout<<'\n';
    }
}