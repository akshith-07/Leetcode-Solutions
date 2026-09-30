class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.length();
        string count ="";
        string repeatChar ="";
        int r=0;
        while(r<n){
            if(s[r]=='['){
                st.push(repeatChar);
                st.push(count);
                repeatChar="";
                count="";
            }
            else if(s[r]==']'){
                int num = stoi(st.top());
                st.pop();
                string temp1 ="";
                for(int i=0;i<num;i++){
                    temp1+= repeatChar;
                }
                string temp2= st.top();
                st.pop();
                repeatChar = temp2+temp1;
            }  
            else if(s[r]>='0' && s[r]<='9'){
                count += s[r];
            }
            else if(s[r]>='a' && s[r]<='z'){
                repeatChar+=s[r];
            }
            r++; 
            
        }

        return repeatChar;
       
    }
};