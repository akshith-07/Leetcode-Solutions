class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string longprefix="";
        unordered_map<int , char> umap;
        string temp = strs[0];
        if(strs.size() ==1){
            return temp;
        }

        for(int i =0;i<temp.length();i++){
            umap[i]=temp[i];
        }

        for(int i=1;i<strs.size();i++){
            string temp = strs[i];
            int matchLen = 0 ;
            for(int j =0;j<temp.length();j++){
                if(umap[j]==temp[j]){
                    matchLen++;
                }else{
                    break;
                }
            }
            for(int k=matchLen; umap.count(k); k++){
                umap.erase(k);
            }
        }

        for(int i=0;umap.count(i);i++){
            longprefix+=umap[i];
        }

        return longprefix;


    }
};