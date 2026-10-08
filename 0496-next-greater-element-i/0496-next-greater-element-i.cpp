class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[i]>st.top()){
                umap[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        while(!st.empty()){
            umap[st.top()] = -1;
            st.pop(); 
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(umap[nums1[i]]);
        }

        return ans;

    }
};