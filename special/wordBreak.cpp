#include<bits/stdc++.h>
using namespace std;

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

int main() {
    string s="catsanddog";
    vector<string> words={"cat","cats","and","sand","dog"};
    
    vector<string> ans=wordBreak(s,words);

    for(const auto& line: ans) cout<<line<<'\n';

    return 0;
}