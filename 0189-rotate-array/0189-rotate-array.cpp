class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k=k%nums.size();

        if(k==0)
        {
            return;
        }
        int temp[k];
        int n=nums.size();
         for (int i = n - k; i < n; i++) 
         {
            temp[i - (n - k)] = nums[i];
        } 
        

        for (int i = n - k - 1; i >= 0; i--) 
        {
            nums[i + k] = nums[i];
        }

        for(int i=0;i<k;i++)
        {
            nums[i]=temp[i];
        }

      
    }
};