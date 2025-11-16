#include<bits/stdc++.h>
using namespace std;

int change(int target,vector<int>& coins) {
    int n=coins.size();
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));

    for(int i=0;i<=n;i++) dp[i][0]=1;

    for(int i=1;i<=n;i++) {
        for(int t=1;t<=target;t++) {
            if(coins[i-1]<=t) 
                dp[i][t]=dp[i][t-coins[i-1]] + dp[i-1][t];
            else dp[i][t]=dp[i-1][t];
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> coins={1,2,3};
    int target=4;
    cout<<change(target,coins);
    return 0;
}
