class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {

        unordered_map<char , int> umap;
        for(auto it:jewels){
            umap[it] = 1;
        }

        int count=0;

        for(auto it:stones){
            if(umap[it]==1){
                count++;
            }
        }

        return count;
        
    }
};