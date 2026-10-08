class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        for(int i=0;i<nums2.size();i++){
            int max =-1;
            for(int j=i+1;j<nums2.size();j++){
                if(nums2[j]>nums2[i]){
                    max = nums2[j];
                    break;
                }
            }
            umap[nums2[i]]=max;
        }

        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(umap[nums1[i]]);
        }

        return ans;

    }
};