//Brute Force Solution
//Time Complexity: O(n^2) where n is the size of the input array

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int n=arr.size();
        int res=0;
        for(int st=0;st<n;st++){
            int currSum=0;
            for(int end=st;end<n;end++){
               currSum+=arr[end];
               if(currSum==0)
                res++;
            }
        }
        return res;
    }
};
