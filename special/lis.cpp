class Solution {
public:
    int t[2502][2502];

    int solve(int i, int prev, vector<int>& nums) {
        if(t[i][prev+1]!=-1) return t[i][prev+1];
        if(i==nums.size()) return 0;
        
        int maxi=INT_MIN;
        int len1=0+solve(i+1,prev,nums);
        int len2=0;
        if(prev==-1 || nums[prev]<nums[i]) 
            len2=1+solve(i+1,i,nums);
        
        return t[i][prev+1]=max(len1,len2);
    }
 
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,nums);
    }
};