class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string temp="";
        while(temp.length()<=b.length()){
            temp +=a;
            if(temp.contains(b)){
                return count;
            }
            count++;
        }
        temp+=a;
        if(temp.contains(b)){
            return count;
        }
        return -1;
    }
};