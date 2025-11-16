//Method 1 (Brute Force Solution):
//Time Complexity: O(n) where n is the size of the input array
//Space Complexity: o(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n=nums.size();
       vector<int> res(n);
       k=k%n;
       for(int i=0;i<n;i++){
           int t=(i+k)%n;
           res[t]=nums[i];
       }
       nums=res;
    }
};

// Method 2 (Optimized Solution):
//Time Complexity: O(n) where n is the size of the input array
//Space Complexity: O(1) 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
// Reverse the starting n-k elements
        reverse(nums.begin(),nums.end()-k);
// Reverse the last k elements
        reverse(nums.end()-k,nums.end());
// Reverse the entire array
        reverse(nums.begin(),nums.end());
    }
};  
