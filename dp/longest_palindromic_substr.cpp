class Solution {
public:
    bool t[1001][1001];

    bool solve(int i, int j, string& s) {
        if(t[i][j]) return t[i][j];

        if(i>=j) return true;
        if(s[i]==s[j]) return t[i][j]=solve(i+1,j-1,s);
        return t[i][j]=false;
    }

    string longestPalindrome(string s) {
        int st=0, maxlen=INT_MIN;
        memset(t,false,sizeof(t));

        for(int i=0;i<s.size();i++) {
            for(int j=i;j<s.size();j++) { 
                if(solve(i,j,s)) {
                    if(maxlen<j-i+1) {
                        maxlen=j-i+1;  
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxlen);
    }
};