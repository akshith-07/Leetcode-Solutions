class Solution {
public:
    string RLE(string s){
        string temp="";
        int n = s.length();
        int r=0;
        while(r<n){
            int count=1;
            while(s[r]==s[r+1]){
                r++;
                count++;
            }
            string concat = to_string(count) + s[r];
            temp+=concat;
            r++;
        }

        return temp;
    }
    string countAndSay(int n) {

        string compression = "1";
        for(int i=1;i<n;i++){
            compression = RLE(compression);
        }   

        return compression;

    }
};