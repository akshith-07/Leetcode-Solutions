class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        int charCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') charCount++;
            if(s[i]==')'){
                if(charCount==0) {
                    count++;
                }else{
                    charCount--;
                }
            }
            
        }
        return count+charCount;
        
    }
};