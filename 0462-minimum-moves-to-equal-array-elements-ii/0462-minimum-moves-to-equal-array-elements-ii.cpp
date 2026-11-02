class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // median is what we want, mean if we wanted minimum sum of squares of differences

        int n = nums.size();
        int c = n % 2 == 0 ? (nums[n/2 - 1] + nums[n/2]) / 2 : nums[n/2];

        int ans = 0;

        for (int x : nums) ans += abs(x - c);

        return ans;
    }
};