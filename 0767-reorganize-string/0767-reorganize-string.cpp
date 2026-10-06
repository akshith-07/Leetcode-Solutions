class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        vector<int> charArr(26,0);
        priority_queue<pair<int, int>> maxHeap;
        vector<int>stringArr(n);
        string ans ="";

        for(auto it:s){
            charArr[it-'a']++;
        }
        
        for(int i=0;i<charArr.size();i++){
            if(charArr[i]> ((n+1)/2)) 
                return "";
            if(charArr[i]>0)
                maxHeap.push({charArr[i], i});
        }
        int index = 0;
        while(!maxHeap.empty()){
            auto top= maxHeap.top();
            maxHeap.pop();
            for(int i=0;i<top.first;i++){
                stringArr[index] = top.second;
                index+=2;

                if(index>=n){
                    index = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            ans+=stringArr[i]+'a';
        }

        return ans;

        
    }
};