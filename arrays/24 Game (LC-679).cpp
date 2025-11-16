class Solution {
public:
    bool solve(vector<double> & nums){
        if(nums.size()==1){
            if(abs(nums[0]-24)<=0.1)
                return true;
            else
                return false;
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==j)
                    continue;
                double a=nums[i];
                double b=nums[j];
                vector<double> temp;
                for(int k=0;k<nums.size();k++){
                    if(k==i || k==j)
                        continue;
                    temp.push_back(nums[k]);
                }
                vector<double> operations={a+b,a-b,a*b};
                if(b!=0.0)
                    operations.push_back(a/b);
                for(int k=0;k<operations.size();k++){
                    temp.push_back(operations[k]);
                    if(solve(temp)==true)
                        return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i=0;i<4;i++){
            nums.push_back((double)cards[i]);
        }
        bool res=solve(nums);
        return res;
    }
};
