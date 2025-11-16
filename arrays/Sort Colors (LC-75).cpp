class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=n-1;
        int i=0;
        while(i<=end){
            if(nums[i]==0){
                swap(nums[i],nums[st]);
                i++,st++;
            }
            else if(nums[i]==1){
                i++;
            }
            else{
                swap(nums[i],nums[end]);
                end--;
            }
        }
    }
};