#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    // A static set to store all balanced numbers, initialized once.
    static set<long long> balancedNumbers;

    // Static helper function to generate and return the set of balanced numbers.
    static set<long long> initBalancedNumbers() {
        set<long long> s;
        // Base digit combinations. Given n <= 10^6, we need to check
        // 6-digit numbers (like 666666) and 7-digit numbers (like 1224444).
        // We include the next 8-digit one just to be safe for the upper_bound.
        vector<string> bases = {
            "1", "22", "122", "333", "1333", "4444", "14444", "22333", "55555",
            "122333", "155555", "224444", "666666", "1224444", "1666666", 
            "2255555", "3334444", "7777777", 
            "12255555" // Smallest 8-digit balanced number
        };

        for (string base : bases) {
            // Sort the string to ensure next_permutation generates all unique permutations
            sort(base.begin(), base.end());
            do {
                // Convert the permutation string to long long and insert into the set
                s.insert(stoll(base)); 
            } while (next_permutation(base.begin(), base.end()));
        }
        return s;
    }

public:
    int nextBeautifulNumber(int n) {
        // Find the first element in the set that is strictly greater than n
        auto it = balancedNumbers.upper_bound(n);
        
        // Return the found number. 
        // Given constraints and our list, 'it' should never be end(), 
        // but this check is good practice.
        return (it != balancedNumbers.end()) ? *it : -1;
    }
};

// Initialize the static member variable outside the class
set<long long> Solution::balancedNumbers = Solution::initBalancedNumbers();