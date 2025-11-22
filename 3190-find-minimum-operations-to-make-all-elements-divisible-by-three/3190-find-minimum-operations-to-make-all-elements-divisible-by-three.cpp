class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int countNotDivisibleByThree=0;
        for(auto x: nums) countNotDivisibleByThree+=(x%3!=0);
        return countNotDivisibleByThree;
    }
};