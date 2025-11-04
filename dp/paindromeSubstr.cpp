class Solution {
public:
    int t[1001][1001];
    bool pal(int i, int j, string& s) {
        if(t[i][j]==0) return false;
        if(t[i][j]==1) return true;        

        if(i>=j) return true;
        if(s[i]==s[j]) return t[i][j]=pal(i+1,j-1,s);

        else return t[i][j]=false;
    }

    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            for(int j=i;j<s.size();j++) {
                if(pal(i,j,s)) cnt++;
            }
        }
        return cnt;
    }
};