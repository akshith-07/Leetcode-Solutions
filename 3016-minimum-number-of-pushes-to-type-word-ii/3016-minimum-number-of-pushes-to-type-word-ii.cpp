class Solution {
public:
    int minimumPushes(string word) {
    vector<int>arr(26,0);
    for(auto x:word) arr[x-97]++; 
    int ans=0;
    sort(arr.begin(),arr.end(),greater<int>());
     for(int i=0;i<26;i++) ans=ans+arr[i]*(i/8+1);
      return ans;
    }
};