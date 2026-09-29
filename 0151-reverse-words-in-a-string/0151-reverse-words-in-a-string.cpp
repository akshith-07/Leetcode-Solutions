class Solution {
public:
    string reverseWords(string s) {
        
        string answer = "";
        string temp="";

        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!=' '){
                temp+=s[i];
            }else{
                if(!temp.empty()){
                    reverse(temp.begin(),temp.end());
                    if(!answer.empty()) answer+=" ";
                    answer += temp;
                    temp="";
                }
            }
           
        }
        if(!temp.empty()){
            reverse(temp.begin(),temp.end());
            if(!answer.empty()) answer+=" ";
            answer+=temp;
        }

        return answer;

    }
};