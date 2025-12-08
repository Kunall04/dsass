#include <bits/stdc++.h>
using namespace std;

class ActivitySelection {
public:
    int activitySelection(vector<int>& arr, vector<int>& dep) {

        int n = arr.size();
        vector<pair<int,int>> act(n); 
        // pair = {start, end}

        for (int i = 0; i < n; i++) {
            act[i] = {arr[i], dep[i]};
        }

        // sort by ending time
        sort(act.begin(), act.end(), 
            [](auto &a, auto &b) { 
                return a.second < b.second; 
            }
        );

        int count = 1;
        int last = act[0].second;

        for (int i = 1; i < n; i++) {
            if (act[i].first > last) {
                count++;
                last = act[i].second;
            }
        }

        return count;
    }
};