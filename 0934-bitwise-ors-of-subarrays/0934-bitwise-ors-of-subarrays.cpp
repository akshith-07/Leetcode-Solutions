class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res, cur;

        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);
            for (int x : cur) {
                next.insert(x | num);
            }
            cur = next;
            for (int x : cur) res.insert(x);
        }

        return res.size();
    }
};