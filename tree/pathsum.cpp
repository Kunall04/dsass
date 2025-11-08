class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>> &ans,vector<int> &arr, int target) {
        if(root==NULL) return;
        target-=root->val; 
        arr.push_back(root->val); 

        if(target==0 && !root->left && !root->right) {
            ans.push_back(arr);
            arr.pop_back(); 
        } 

        dfs(root->left,ans,arr,target);
        dfs(root->right,ans,arr,target);
        
        arr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        dfs(root, ans, arr,target);
        return ans;
    }
};