#include <bits/stdc++.h>
using namespace std;

    int minPlatform(vector<int>& arr, vector<int>& dep) {

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int count = 0;
        int ans = 0;

        while (i < arr.size() && j < dep.size()) {

            if (arr[i] <= dep[j]) {
                count++;
                i++;
            } 
            else {
                count--;
                j++;
            }

            ans = max(ans, count);
        }

        return ans;
    }