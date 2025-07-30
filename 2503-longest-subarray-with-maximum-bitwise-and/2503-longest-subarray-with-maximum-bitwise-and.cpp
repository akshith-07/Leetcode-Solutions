class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maximum = *max_element(nums.begin(), nums.end());

        int maxx = 0;
        int length = 0;

        for (int num : nums) {
            if (num == maximum) {

                length++;
                maxx = max(maxx, length);
            } else {

                length = 0;
            }
        }

        return maxx;
    }
};