class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string ans = "";
        for(char c : s){
         if(c >= 'a' && c <= 'z'){
            ans.push_back(c);
         }

         else if(c == '*'){
            if(!ans.empty()) ans.pop_back();
         }
         else if(c=='#'){
            ans+=ans;
         }else if(c == '%'){
            reverse(ans.begin(),ans.end());
         }
        }
        return ans;

    }
};