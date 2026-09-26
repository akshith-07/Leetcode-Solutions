class Solution {
public:
    string findValue(string charKey ,unordered_map<string , string> &umap){
       if(umap.count(charKey)){
            return umap[charKey];
       }
        return "?";
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string output = "";
        int n = s.length();
        bool foundKey = false;
        string charKey = "";
        unordered_map<string,string> umap;

        for(auto it:knowledge){
            umap[it[0]]=it[1];
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                foundKey = true;
                continue;
            }
            if(foundKey){
                if(s[i]==')'){
                    output += findValue(charKey , umap);
                    foundKey=false;
                    charKey="";
                }else{
                    charKey += s[i];
                }     
            }else{
                output+=s[i];
            }

        }

        return output;
    }
};