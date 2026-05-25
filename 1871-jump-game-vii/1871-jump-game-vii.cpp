class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
       int n = s.size();

       queue<int> q;
       q.push(0);

       vector<int> vis(n,0);
       vis[0] = 1;

       int further = 0;

       while(!q.empty()){

            int idx = q.front();
            q.pop();

            if(idx == n-1) return true;

            int l = max(further + 1, idx + minJump);
            int r = min(idx + maxJump, n - 1);

            for(int k=l; k<=r; k++){

                if(s[k] == '0' && !vis[k]){

                    vis[k] = 1;
                    q.push(k);
                }
            }

            further = max(further, r);
       }

       return false;
    }
};