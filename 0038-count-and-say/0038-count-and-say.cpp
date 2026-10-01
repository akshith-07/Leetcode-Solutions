class Solution {
public:
    string compression(string str, int n){
        if(n==1){
            return str;
        }

        string temp="";
        int length = str.length();
        int r=0;
        while(r<length){
            int count=1;
            while(str[r]==str[r+1]){
                r++;
                count++;
            }
            string concat = to_string(count) + str[r];
            temp+=concat;
            r++;
        }
        cout<<temp<<" ";
        return compression(temp , n-1); 

    }

    string countAndSay(int n) {
        return compression("1", n);
    }
       
};