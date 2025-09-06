class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        auto ops = [&](vector<int>& q) {
            long long res0 = 0, x = 1;
            while (x < q[0]) {
                res0++;
                x *= 4;
            }
            long long res1 = res0, res = 0, prev = q[0];
            while (x <= (long long)q[1] * 4) {
                res += res1 * (min((long long)x, (long long)q[1] + 1) - prev);
                prev = x;
                res1++;
                x *= 4;
            }
            return (res + 1) / 2;
        };
        long long ans = 0;
        for (auto& q : queries) ans += ops(q);
        return ans;
    }
};