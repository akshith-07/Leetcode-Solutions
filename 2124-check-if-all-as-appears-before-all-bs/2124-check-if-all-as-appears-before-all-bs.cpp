class Solution {
public:
    bool checkString(string s) {
        bool flag = false;

        for(char ch : s) {
            if(flag && ch == 'a')
                return false;

            if(ch == 'b')
                flag = true;
        }

        return true;
    }
};