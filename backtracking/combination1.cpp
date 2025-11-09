class Solution {
public:
    void countSub(int idx,int target, vector<int>& candidates, vector<int>&ds, vector<vector<int>>& ultimate){
        if(idx==candidates.size()){
            if(target==0){
                ultimate.push_back(ds);
            }
            return ;
        }

        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            countSub(idx, target-candidates[idx], candidates, ds, ultimate);
            ds.pop_back();
        }
        countSub(idx+1, target, candidates, ds, ultimate);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ultimate;
        vector<int> ds;
        countSub(0, target, candidates, ds, ultimate);
        return ultimate;
    }
};