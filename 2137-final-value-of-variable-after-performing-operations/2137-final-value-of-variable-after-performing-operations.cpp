class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (const string& op : operations) {
            if (op[0] == '+' || op[2] == '+')
                x++;
            else
                x--;
        }
        return x;
    }
};