class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        int left = 0;
        int right = 0;

        string answer="";

        while(left<n && right <n){
            if(s[right]!=' '){
                right++;
            }else{
                string temp = s.substr(left , right-left);
                if(answer.empty()) answer += temp;
                else answer = temp + " "+ answer;
                left=right+1;
                right++;
                while(right<n && s[right]==' '){
                    right++;
                    left++;
                }
            }
        }
        if(left<right){
            string temp = s.substr(left , right-left);
            if(answer.empty()) answer += temp;
            else answer= temp +" "+ answer;
        }
       
        return answer;


    }
};