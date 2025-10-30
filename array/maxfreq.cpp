class Solution {
public:
    int maxFrequencyElements(vector<int>& nums){
        unordered_map<int,int> mp;
        int mx=0;
        for(int x:nums)mx=max(mx,++mp[x]);
        int ans=0;
        for(auto &p:mp)if(p.second==mx)ans+=p.second;
        return ans;
    }
};
