class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        
        unordered_map<char , int> umap;
        for(auto it:s){
            umap[it]++;
        }

        for(auto it:t){
            if(umap[it]==0){
                return false;
            }
            umap[it]--;
        }
        return true;
    }
};