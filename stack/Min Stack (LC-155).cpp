//Brute Force Solution
//Time Complexity: O(1)
//Space Complexity: O(2n) where n is the size of the stack

class MinStack {
public:
    stack<pair<int,int>> st; 
    MinStack() {}
    void push(int val) {
        if(st.empty())
            st.push({val,val});
        else
            st.push({val,min(val,st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

//Optimized Solution
//Time Complexity: O(1)
//Space Complexity: O(n) where n is the size of the stack

class MinStack {
public:
    stack<long long> st; 
    long long mini=INT_MAX;
    MinStack() {}
    void push(int value) {
        long long val=value;
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>mini)
                st.push(val);
            else{
                st.push(2*val-mini);
                mini=val;
            }
        }
    }
    
    void pop() {
        if(st.top()>mini)
            st.pop();
        else{
            mini=2*mini-st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>mini)
            return st.top();
        return mini;
    }
    
    int getMin() {
        return mini;
    }
};
