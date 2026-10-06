class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 0;
        string temp="";
        while(temp.length()<b.length()){
            temp +=a;
            count++;
        }
        if(temp.contains(b)){
            return count;
        }
        temp+=a;
        count++;
        if(temp.contains(b)){
            return count;
        }
        return -1;
    }
};