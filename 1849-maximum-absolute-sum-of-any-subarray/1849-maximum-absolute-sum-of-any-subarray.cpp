class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=0, minSum=0, ans=0;
        for(int x: nums){
            maxSum=max(0, maxSum+x);
            minSum=min(0, minSum+x);
            ans=max(ans, maxSum-minSum);// More like Kadane, 
                                        // but this can be pulled outside the loop
        }
        return ans;
    }
};