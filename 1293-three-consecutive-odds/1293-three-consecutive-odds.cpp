class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& a) {
        int n=a.size();
        if(n<3)return false;
        for(int i=0;i<n-2;i++){
            if(a[i]%2 && a[i+1]%2 && a[i+2]%2){
                return true;
            }
        }
        return false;
    }
};