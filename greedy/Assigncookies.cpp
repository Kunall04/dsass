
class AssignCookies {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        int count = 0;
        vector<bool> used(n, false);

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!used[j] && s[i] >= g[j]) {
                    used[j] = true;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

