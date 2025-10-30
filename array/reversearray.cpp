class Solution {
public:
    vector<int> reverseArray(vector<int>& a){
        int i=0,j=a.size()-1;
        while(i<j)swap(a[i++],a[j--]);
        return a;
    }
};