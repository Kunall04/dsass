class Solution {
public:
    int t[10001];

    int solve(int i, vector<int>& arr) {
        int n=arr.size();
        if(i>=n-1) return 0;
        if(t[i]!=-1) return t[i]; 

        int mini=INT_MAX-1;
        for(int x=1;x<=arr[i] && i+x<n ;x++) {
            // 1+min(all the further steps)
            mini=min(mini,1+solve(i+x,arr));
        }
        return t[i]=mini;
    }

    int jump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        // int mini=INT_MAX;
        return solve(0,nums);
    }
};