class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> st;
        vector<int> res;
        for(int ele:asteroids){
            bool exist= true;
            while(!st.empty() && ele<0 && st.top()>0){
                if(abs(ele)>st.top()){
                        st.pop();
                        continue;
                }
                else if(abs(ele)==st.top())
                    st.pop();
                exist=false;
                break;
            }
            if(exist)
                st.push(ele);
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};