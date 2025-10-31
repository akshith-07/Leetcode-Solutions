class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> res;
        for (int num : nums){
            int val = num >= 1000 ? num - 1000 : num;
            if (nums[val] + 1000 >= 2000)
                res.push_back(val);
            else
                nums[val] += 1000;
        }
        return res;
    }
};