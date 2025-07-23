class Solution {
public:
    int maxPoints(string& s, string si, int val) {
        int points = 0, n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.size() == 0) {
                st.push(s[i]);
            } else {
                if (s[i] == si[1] && st.top() == si[0]) {
                    st.pop();
                    points += val;
                } else {
                    st.push(s[i]);
                }
            }
        }
        s = "";
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return points;
    }
    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if (x < y)
            swap(s1, s2), swap(x, y);
        return maxPoints(s, s1, x) + maxPoints(s, s2, y);
    }
};