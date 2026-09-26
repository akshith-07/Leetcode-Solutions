class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> mp;

        for (const auto& it : knowledge) {
            mp.emplace(it[0], it[1]);
        }

        string ans;
        ans.reserve(s.size());

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != '(') {
                ans += s[i];
                continue;
            }

            string key;

            while (s[++i] != ')') {
                key += s[i];
            }

            auto it = mp.find(key);

            if (it != mp.end())
                ans += it->second;
            else
                ans += '?';
        }

        return ans;
    }
};