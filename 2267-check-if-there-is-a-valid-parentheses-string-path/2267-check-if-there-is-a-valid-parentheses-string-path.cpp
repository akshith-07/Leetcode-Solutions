class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int length = m + n - 1;

        if (length % 2 != 0 || grid[0][0] != '(' ||
            grid[m - 1][n - 1] != ')') {
            return false;
        }

        vector<bitset<201>> dp(n);

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                bitset<201> reachable;

                if (row > 0) reachable |= dp[col];
                if (col > 0) reachable |= dp[col - 1];
                if (row == 0 && col == 0) reachable.set(0);

                dp[col] = grid[row][col] == '('
                    ? (reachable << 1)
                    : (reachable >> 1);
            }
        }

        return dp[n - 1].test(0);
    }
};