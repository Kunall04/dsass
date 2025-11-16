#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &arr, int target,
         vector<int> &curr, vector<vector<int>> &ans)
{
    if (target == 0) {
        ans.push_back(curr);
        return;
    }

    if (i == arr.size()) return;

    dfs(i + 1, arr, target, curr, ans);

    if (arr[i] <= target) {
        curr.push_back(arr[i]);
        dfs(i + 1, arr, target - arr[i], curr, ans);
        curr.pop_back();
    }
}

vector<vector<int>> subsetSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> curr;
    dfs(0, arr, target, curr, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1,2,1};
    int target = 3;

    vector<vector<int>> res = subsetSum(arr, target);

    for(auto &v : res){
        cout << "[ ";
        for(int x : v) cout << x << " ";
        cout << "]";
    }

    return 0;
}
