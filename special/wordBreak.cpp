class Solution {
public:
    void solve(int i, string& s,string& w,unordered_set<string>& st, vector<string>& ans) {
        if(i==s.size()) {
            ans.push_back(w);
            return;
        }

        for(int j=i;j<s.size();j++) {
            string sub=s.substr(i,j-i+1);
            if(st.count(sub)) {
                string prev=w;
                if(!w.empty()) w+=" ";

                w+=sub;
                solve(j+1,s,w,st,ans);

                // w.pop_back();
                w=prev;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& words) {
        unordered_set<string> st;

        for(const auto& word: words) st.insert(word);

        vector<string> ans;
        string w;
        solve(0,s,w,st,ans);

        return ans;
    }
};