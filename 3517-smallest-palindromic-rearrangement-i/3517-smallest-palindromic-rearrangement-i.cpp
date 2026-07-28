class Solution {
public:
    static string smallestPalindrome(string& s) {
        const int n=s.size(), n0=n/2;
        int freq[26]={0};
        unsigned seen=0;
        for(int i=0; i<n0; i++){
            const int idx=s[i]-'a';
            freq[idx]++;
            seen|=(1<<idx);
        }
        int l=0;
        for(; seen; seen&=(seen-1)){
            const int x=__builtin_ctz(seen);
            const int f=freq[x];
            const char c='a'+x;
            fill(s.begin()+l, s.begin()+l+f, c);
            fill(s.rbegin()+l, s.rbegin()+l+f, c);
            l+=f;
        }
        return s;
    }
};