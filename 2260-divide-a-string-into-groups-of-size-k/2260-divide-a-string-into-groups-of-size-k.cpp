class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> v;
        for (int i = 0; i < n; i += k) {
            string str = s.substr(i, k);
            while (str.size() < k) str += fill;
            v.push_back(str);
        }
        return v;
    }
};