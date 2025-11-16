class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int minidx,maxidx;
// Find the minimum and maximum element and their indexes 
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                maxidx=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                minidx=i;
            }
        }
// Find the minimum of the case when both the elements are deleted from the same side either left or right
        int temp1=min(1+max(minidx,maxidx),max(n-minidx,n-maxidx));
// Find the minimum of the case when both the elements are deleted from opposite sides(if one from left then the other from right)
        int temp2=min(minidx+1+n-maxidx,maxidx+1+n-minidx);
        return min(temp1,temp2);
    }
};
