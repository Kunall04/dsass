//Brute Force Solution
//Time Complexity: O(n^2) where n is the size of the input array

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int currSum=0;
        for(int i=0;i<n;i++){
            int currSum=0;
            for(int end=i;end<n;end++){
                currSum+=nums[end];
                if(currSum>maxSum)
                    maxSum=currSum;
            }
        }
        return maxSum;
    }
};


//Optimized Solution
//Time Complexity: O(n) where n is the size of the input array

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            if(currSum>maxSum)
                maxSum=currSum;
            if(currSum<0)
                currSum=0;
        }
        return maxSum;
    }
};
