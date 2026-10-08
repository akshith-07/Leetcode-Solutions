class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto it:tokens){
            if (it == "+" || it == "-" || it == "*" || it == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int temp;
                if(it=="+") temp = a+b;
                else if(it=="-") temp = a-b;
                else if(it=="*") temp = a*b;
                else temp = a/b;
                st.push(temp);
                
            }else{
                int temp = stoi(it);
                st.push(temp);
            }
        }
        return st.top();
    }
};