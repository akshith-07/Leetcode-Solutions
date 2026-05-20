class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int n=A.size();
        vector<int>ans(n,0);
        for(int i=0;i<A.size();i++){
              mp[A[i]]++;mp[B[i]]++;
              int ct=0;
              for(auto&it : mp)if(it.second==2)ct++;
              ans[i]=ct;
        }
        return ans;
    }
};