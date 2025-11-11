class Solution {
  public:
    string findOrder(vector<string> &w) {
        int n=w.size();
        
        unordered_set<char> st;
        for(auto& s: w) {
            for(auto& c: s) st.insert(c);
        }
        int k=st.size();
        
        vector<vector<int>> adj(26);
        
        for(int i=0;i<n-1;i++) {
            string p=w[i];
            string q=w[i+1];
            int l=min(p.size(),q.size());
            
            // int j=0;
            // while(j<l && p[j]==q[j]) j++;
            // if(j<l) adj[p[j]-'a'].push_back(q[j]-'a');
            bool f=false;
            for(int j=0;j<l;j++) {
                if(p[j]!=q[j]) {
                    adj[p[j]-'a'].push_back(q[j]-'a');
                    f=true;
                    break;
                }
            }
            
            if(!f && p.size()>q.size()) return "";
        }
        
        vector<int> ind(26,0);
        for(int i=0;i<26;i++) {
            for(auto it: adj[i]) {
                // if(ind[it]==0) ind[it]++;
                ind[it]++;
            }
        }
        
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<26;i++) {
            if(ind[i]==0 && st.count(i+'a')) q.push(i);
        }
        
        // int cnt=0;
        while(!q.empty()) {
            int node=q.front();q.pop();
            
            // cnt++;
            topo.push_back(node);
            for(auto it: adj[node]) {
                ind[it]--;
                if(ind[it]==0) q.push(it);
            }
        }
        
        string ans;
        for(auto& c: topo) {
            ans+=char(c+'a');
        }
        if(topo.size()<k) return "";
        return ans;
    }
};