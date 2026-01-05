class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        long sum =0;

        int neg =0;

        int mini =INT_MAX;

        int n = matrix.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                int val = matrix[i][j];
                sum += abs(val);

                if(val<0)neg++;

                mini = min(mini,abs(val));

            }
        }

        if(neg%2==0)return sum;
        return sum-2*mini;


        
    }
};