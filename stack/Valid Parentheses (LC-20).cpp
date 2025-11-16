//Optimized Code
//Time Complexity: O(n) where n is the size of the input string

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            //if the stack is empty and the element is a closing bracket
            //this means no open bracket is associated to it, hence this sequence is not valid
            if(st.empty()){
                if((s[i]=='}' || s[i]==']' || s[i]==')'))
                    return false;
                st.push(s[i]);
            }

            //if the current element is a closing bracket and the top of the stack is the opening bracket
            // of the same kind then pop from the stack
            else{
            if(st.top()=='(' && s[i]==')') 
                st.pop();
            else if(st.top()=='{' && s[i]=='}') 
                st.pop();
            else if(st.top()=='[' && s[i]==']') 
                st.pop();
            else
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};