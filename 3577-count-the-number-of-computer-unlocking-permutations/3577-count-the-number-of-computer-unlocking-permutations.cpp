class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int root = complexity[0];
        long long mod = 1000000007;

        for(int i=1;i<n;i++){
            if(complexity[i]<=root) return 0;
        }

        long long ans=1;
        for(int i=1;i<=n-1;i++)
        {
            ans*=i;
            if(ans>mod) ans%=mod;
        }
        return ans;
        
    }
};