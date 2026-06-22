class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // We only need to track 5 characters
        unordered_map<char, int> freq;
        
        // 1. Fill our inventory
        for (char c : text) {
            if (c == 'b' || c == 'a' || c == 'l' || c == 'o' || c == 'n') {
                freq[c]++;
            }
        }
        
        // 2. Each "balloon" needs TWO 'l's and TWO 'o's
        // So 4 'l's can only contribute to 2 balloons
        int b = freq['b'];
        int a = freq['a'];
        int l = freq['l'] / 2;
        int o = freq['o'] / 2;
        int n = freq['n'];
        
        // 3. The bottleneck (minimum) determines the final count
        return min({b, a, l, o, n});
    }
};