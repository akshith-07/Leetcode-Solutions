class Solution {
public:
    bool checkPalindrome(string s){
        int left = 0 ; 
        int right = s.length()-1;

        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
    bool isPalindrome(string s) {
        if(s==" "){
            return true;
        }

        string str = "";
        int n = s.length();
        int i=0;
        while(i<n){
            if(s[i]>='A' && s[i]<='Z'){
                char temp = s[i]+('a'-'A');
                str += temp;
            }else if(s[i]>='a' && s[i]<='z'|| s[i]>='0' && s[i]<='9'){
                str += s[i];
            }
            i++;
        }

        return checkPalindrome(str);
        
    }
};