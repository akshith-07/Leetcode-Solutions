class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long sum = 0;
        for (auto x: nums)   sum += x;
        if (sum % p == 0)   return 0;
        
        int tarRem = sum % p;
        long long  preSum = 0;
        unordered_map<int, int>mp;
        mp[0] = -1;
        int ans = INT_MAX;
        
        for (int i=0;i<nums.size();i++)
        {
            preSum += nums[i];
            int currRem = preSum % p;
            int reqRem = (currRem - tarRem + p) % p; //for handling negative elements:
            
            if (mp.find(reqRem) != mp.end())
            {
                ans = min(ans, i - mp[reqRem]);
                mp[currRem] = i;
            }
            else   mp[currRem] = i;
        }
        
        return (ans == INT_MAX || ans == nums.size()) ? -1 : ans;
    }
};