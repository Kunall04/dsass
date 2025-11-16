//Brute Force Solution
//Time Complexity: O(n^2) where n is the size of the input array
//Space Complexity: O(1) 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int prefsum=0;
      int suffsum=0;
      //Traverse over each element
      for(int i=0;i<nums.size();i++){
        int prefsum=0;
        int suffsum=0;
        
      //find the prefix sum of the element
        for(int j=0;j<i;j++)
           prefsum+=nums[j];

        //find the suffix sum of the element
        for(int j=i+1;j<nums.size();j++)
           suffsum+=nums[j];

        //If the prefix sum and the suffix sum are equal, return the index
        if(prefsum==suffsum)
        return i;
      }  
      return -1;
    }
};

//Optimized Solution
//Time Complexity: O(n) where n is the size of the input array
//Space Complexity: O(1) 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int prefsum=0;
      int suffsum=0;
      int total=0;
      for(int ele:nums)
      total+=ele;

      //prefix sum for index 0 is 0 and if the suffix sum is also zero then 0 is the answer
      if(total-nums[0]==0)
      return 0;

      //Traverse over each element of the array staring from index 1
      for(int i=1;i<nums.size();i++){
        prefsum+=nums[i-1];
        suffsum=total-nums[i]-prefsum; // based on the logic that for every element prefix sum + suffix sum + element is equal to total sum of the array
        if(prefsum==suffsum)
        return i;
      } 
      return -1;
    }
};
