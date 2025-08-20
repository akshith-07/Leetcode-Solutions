class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> sm(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                sm[i][j] = matrix[i - 1][j - 1] + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
            }
        int mx = min(n, m);
        int ans = 0;
        for(int i = 1; i <= mx; i++){
            int exp = i * i;
            for(int j = i; j <= m; j++){
                for(int k = i; k <= n; k++){
                    if(exp == (sm[j][k] + sm[j - i][k - i] - sm[j][k - i] - sm[j - i][k]))
                        ans++;
                }
            }
        }
        return ans;
    }
};