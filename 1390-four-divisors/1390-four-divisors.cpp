class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int div_sum = 0;

        for (int n : nums) {
            int div_count = 0, in_sum = 0;

            for (int d = 1; d * d <= n; d++) {
                if (n % d == 0) {
                    int other = n / d;

                    if (d == other) {
                        div_count++;
                        in_sum += d;
                    } else {
                        div_count += 2;
                        in_sum += d + other;
                    }

                    if (div_count > 4)
                        break;
                }
            }

            if (div_count == 4)
                div_sum += in_sum;
        }

        return div_sum;
    }
};