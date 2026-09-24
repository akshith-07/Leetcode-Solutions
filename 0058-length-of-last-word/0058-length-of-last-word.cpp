class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i=s.length()-1;
        bool found = false;
        while(i>=0){
            if(s[i]==' ' && found == true){
                break;
            }else if(s[i]!=' '){
                length++;
                found = true;
            }
            i--; 
        }   
        
        return length;
    }
};