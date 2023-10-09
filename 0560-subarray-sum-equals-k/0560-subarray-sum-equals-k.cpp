class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {


        int n=nums.size();

        unordered_map<int,int>umap;

        umap[0]=1;

        int presum=0;
        int count=0;

        for(int i=0;i<n;i++)
        {
            presum+=nums[i];

            int remove=presum-k;

            count+=umap[remove];

            umap[presum]++;
        }
        
        return count;
    }
};