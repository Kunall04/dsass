#include <bits/stdc++.h>
using namespace std;

    int coinChange(vector<int>& arr, int sum) {
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        // initialize first row
        for (int j = 0; j <= sum; j++) {
            dp[0][j] = INT_MAX - 1;  // no coins → impossible
        }

        // initialize first column
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;  // zero sum needs zero coins
        }

        // fill DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = min(1 + dp[i][j - arr[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (dp[n][sum] == INT_MAX - 1) ? -1 : dp[n][sum];
    }

