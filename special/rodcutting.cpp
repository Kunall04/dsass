int rodCut(vector<int>& price,int n){
    vector<int> len(n);
    for(int i=0;i<n;i++) len[i]=i+1;

    vector<vector<int>> t(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(len[i-1]<=j){
                t[i][j]=max(price[i-1]+t[i][j-len[i-1]],t[i-1][j]);
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][n];
}
