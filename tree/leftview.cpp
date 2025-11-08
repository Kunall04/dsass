class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        if(root==NULL) return arr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            arr.push_back(q.back()->val);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return arr;
    }
};