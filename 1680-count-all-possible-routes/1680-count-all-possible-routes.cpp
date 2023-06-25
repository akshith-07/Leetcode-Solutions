class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
         const int MOD = 1000000007;
        int n = locations.size();    
        
        vector<vector<int>> memo(n, vector<int>(fuel + 1, -1));        
        
        function<int(int,int)> dfs = [&](int city, int remainFuel)          {                        
            if (remainFuel < 0) {
                return 0;
            }                        
            if (memo[city][remainFuel] != -1) {
                return memo[city][remainFuel];
            }
            
            int total = city == finish ? 1 : 0;
            for (int nextCity = 0; nextCity < n; nextCity++) {               
                if (nextCity != city && remainFuel >= abs(locations[nextCity] - locations[city])) {
                    total = (total + dfs(nextCity, remainFuel - abs(locations[nextCity] - locations[city]))) % MOD;
                }
            }
            return memo[city][remainFuel] = total;
        };
        return dfs(start, fuel);    
        
    }
};