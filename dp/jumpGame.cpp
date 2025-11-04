class Solution {
public:
    int t[10001];

    bool solve(int i, vector<int>& arr) {
        if(i==arr.size()-1) return true;

        if(t[i]==0) return false;
        if(t[i]==1) return true;

        for(int x=1;x<=arr[i];x++) {
            if(solve(i+x,arr)) return t[i]=true;
        }
        return t[i]=false;
    }

    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};