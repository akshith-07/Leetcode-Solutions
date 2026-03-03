class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) {
        return '0';
        }    
        int a=(1<<n)-1; 
        int mid=a/2+1;      
        if(k==mid) {
            return '1';
        }
    
        if(k<mid) {
            return findKthBit(n-1,k);
        }
    
        char bit=findKthBit(n-1,a-k+1);
        return bit=='1'?'0':'1';

    }
};