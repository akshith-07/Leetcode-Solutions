class Solution {
public:
    static vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int N=12345, n=grid.size(), m=grid[0].size();
        uint64_t pref=1, suf=1;
        const int mask=(1<<14)-1;

        // prefix
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++) {
                int x=grid[i][j]%=N;
                grid[i][j]+=(pref<<14);
                pref=pref*x%N;
            }

        // suffix
        for (int i=n-1; i>= 0; i--)
            for (int j=m-1; j>= 0; j--) {
                const int x=grid[i][j]&mask;
                const int p=grid[i][j]>>14;

                grid[i][j]=p*suf%N;
                suf=suf*x%N;
            }

        return move(grid);
    }
};
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();