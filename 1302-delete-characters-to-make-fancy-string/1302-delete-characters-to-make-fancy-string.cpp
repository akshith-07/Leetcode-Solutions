class Solution {
public:
    string makeFancyString(string s) {
        string ans = ""; // Local result variable
        rec(0, s, ' ', 0, s.length(), ans);
        return ans;
    }

    void rec(int idx, string& s, char prev, int count, int n, string& ans) {
        if (idx >= n) {
            return;
        }
        if (s[idx] == prev) {
            if (count < 2) {
                ans += s[idx];
            }
            rec(idx + 1, s, prev, count + 1, n, ans);
        } else {
            ans += s[idx];
            rec(idx + 1, s, s[idx], 1, n, ans);
        }
    }
};