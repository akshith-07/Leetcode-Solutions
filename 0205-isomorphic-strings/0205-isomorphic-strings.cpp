class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.length()!=t.length()) return false;
        unordered_map< char , char> umap;
        unordered_set<char> uset;

        for(int i=0;i<s.length();i++){
            if(umap.find(s[i])!=umap.end()){
                if(umap[s[i]]!= t[i])
                    return false;
            }else{
                if(uset.count(t[i])){
                    return false;
                }
            }
            umap[s[i]]=t[i];
            uset.insert(t[i]);
        }
        return true;
    }
    
};