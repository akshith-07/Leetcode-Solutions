class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<vector<int>>q;
        int fresh = 0;

        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int maxMinutes = 0;
        while(!q.empty()){
            vector<int>popped = q.front();
            q.pop();
            int level = popped[2];
            vector<int>x = {-1 , 1 , 0 , 0};
            vector<int>y = {0 , 0 , -1 , 1};

            for(int i=0;i<4;i++){
                int xpoint = popped[0]+x[i];
                int ypoint = popped[1]+y[i];

                if(xpoint>=0 && xpoint<r && ypoint>=0 && ypoint<c){
                    if(grid[xpoint][ypoint]==1){
                        grid[xpoint][ypoint] = 2;
                        q.push({xpoint , ypoint , level+1});
                        fresh--;
                    }
                }
                maxMinutes = max(maxMinutes, level);
            }
        }

        if(fresh>0){
            return -1;
        }else{
            return maxMinutes;
        }
    }
};