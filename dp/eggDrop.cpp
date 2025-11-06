class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& t) {
        if(e==1 || f==0 || f==1) return f;

        if(t[e][f]!=-1) return t[e][f];

        int mini=INT_MAX;
        for(int k=1;k<=f;k++) {
            int temp= 1+max(solve(e-1,k-1,t) , solve(e,f-k,t));

            mini=min(mini,temp);
        }
        return t[e][f]=mini;
    }

    int superEggDrop(int e, int f) {
        vector<vector<int>> t(e+1,vector<int>(f+1,-1));
        return solve(e,f,t);
    }
};