class Solution 
{
public:
    long long countGood(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int i = 0, j = 0;
        long long result = 0, pairs = 0;
        unordered_map<int, int> map;

        while (j < n) 
        {
            // Step 1: Count pairs formed by nums[j]
            pairs += map[nums[j]];

            // Step 2: Update frequency map
            map[nums[j]]++;

            // Step 3: While we have enough pairs
            while (pairs >= k) 
            {
                // Step 3a: Count valid subarrays
                result += (n - j);

                // Step 3b: Shrink window from the left
                map[nums[i]]--;
                pairs -= map[nums[i]]; // After decrement
                i++;
            }

            j++;
        }

        return result;
    }
};