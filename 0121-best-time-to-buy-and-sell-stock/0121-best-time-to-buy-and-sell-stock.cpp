class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int mini=prices[0];
        int gain;
        int profit=0;

        for(int i=1;i<prices.size();i++)
        {
            gain=prices[i]-mini;
            profit=max(profit,gain);
            mini=min(mini,prices[i]);
        }

        return profit;
        
    }
};