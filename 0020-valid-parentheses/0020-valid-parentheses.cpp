class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        int i=1;
        if(n>0) st.push(s[0]);
        while(i<n){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }else{
                if (st.empty()) return false;
                char temp = st.top();
                if((temp=='(' && s[i]==')')|| (temp=='{' && s[i]=='}')|| (temp=='[' && s[i]==']')){
                    st.pop();
                }else{
                    return false;
                }
            }
            i++;
        }

        if(st.empty()) return true;
        else return false;
    }
};