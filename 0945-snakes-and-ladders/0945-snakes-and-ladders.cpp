class Solution {
public:
pair<int,int> get_idx(int id,int m){
         int idx=(id-1+m)/m;
         int idy=(id-1+m)%m;

         if(idx%2==0) idy=(m-1)-idy;
         idx=m-idx;
  return {idx,idy};
}

    int snakesAndLadders(vector<vector<int>>& board) {
        int m=board.size();
        int n=m*m;

        vector<vector<int>>visited(m,vector<int>(m,0));
        queue<pair<int,int>>q;

        q.push({0,1});
        visited[m-1][0]=1;
        
        while(!q.empty()){
         auto [dist,id]=q.front();
         q.pop();

         if(id==n) return dist;

        for(int i=1;i<=6 && id+i<=n ;i++){
            int idd=id+i;
            auto [xx,yy]=get_idx(idd,m);
            if(xx>=0 && yy>=0 && xx<m && yy<m && visited[xx][yy]==0){
                visited[xx][yy]=1;
                if (board[xx][yy] != -1) {
                    q.push({dist + 1, board[xx][yy]});
                } else {
                    q.push({dist + 1, idd});
                }
            }
        }

        }
        return -1;
    }
};