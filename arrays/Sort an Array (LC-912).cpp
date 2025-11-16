//Time Complexity: O(nlogn) where n is the size of the input array

class Solution {
public:
    void merge(int low,int mid,int high,vector<int>& nums){
        int left=low;
        int right=mid+1;
        vector<int> temp;
//Merge the two sorted arrays and insert in a new array
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
// Insert the elements at their correct positions in the original array using the temporary array
        for(int i=0;i<temp.size();i++){
            nums[low+i]=temp[i];
        }
    }
    void mergeSort(int low,int high,vector<int>& nums){
//  Using indexes divide the array in two parts until only one element is left in the array
        if(low>=high)
            return;
        int mid=low+(high-low)/2;
// Calls the function with the first half of the array
        mergeSort(low,mid,nums);
// Calls the function with the second half of the array
        mergeSort(mid+1,high,nums);
// Calls the merge function to merge the two sorted arrays
        merge(low,mid,high,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};
