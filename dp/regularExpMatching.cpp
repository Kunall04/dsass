class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();

        vector<vector<bool>> t(n+1,vector<bool>(m+1,false));
        // bool t[n+1][m+1];
        t[0][0]=true;

        // for(int i=1;i<n+1;i++) {
        //     t[i][0]=false;
        // }
        for(int i=1;i<m+1;i++) {
            if(p[i-1]=='*') t[0][i]=t[0][i-2];
            else t[0][i]=false;
        }

        for(int i=1;i<n+1;i++) {
            for(int j=1;j<m+1;j++) {
                if(s[i-1]==p[j-1] || p[j-1]=='.') 
                    t[i][j]=t[i-1][j-1];

                else if(p[j-1]=='*') {
                    if(t[i][j-2]) {
                        t[i][j]=t[i][j-2];
                    }
                    else if(p[j-2]==s[i-1] || p[j-2]=='.')
                        t[i][j]=t[i-1][j];
                    else t[i][j]=false;
                }
                else t[i][j]=false;
            }
        }
        return t[n][m];
    }
};