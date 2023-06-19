class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0)
        {
            return false;
        }

        long long  num=x;

        long long rev=0;

        while(num)
        {
            long long temp=num%10;
            rev=rev*10+temp;
            num/=10;
        }

        if(rev==x)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};