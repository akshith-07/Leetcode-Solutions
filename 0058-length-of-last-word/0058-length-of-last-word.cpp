class Solution {
public:
    int lengthOfLastWord(string s) {
        // reverse(s.begin(), s.end());
        int length = 0;
        int i=s.length()-1;
        bool found = false;
        while(i>=0){
            if(s[i]==' ' && found == true){
                break;
            }else if(s[i]!=' '){
                cout<<s[i]<<" ";
                 length++;
                 found = true;
            }
            i--; 
        }   
        
        return length;
    }
};