class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arrSum=0;
        int n=nums.size();
      
      //Find the sum of n elements starting from 1
        int totalSum=(n*(n+1))/2;
      
      //Find the sum of all the elements of the array
        for(int ele:nums){
            arrSum+=ele;
        }

      //difference between the total sum and the array sum would be the missing number
        return totalSum-arrSum;
    }
};
