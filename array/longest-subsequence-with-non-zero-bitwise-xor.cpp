#include <vector>

class Solution {
public:
    int longestSubsequence(std::vector<int>& nums) {
        int total_xor = 0;
        bool has_nonzero = false;

        // Calculate the total XOR and look for any element > 0
        for (int num : nums) {
            total_xor ^= num;
            if (num != 0) {
                has_nonzero = true;
            }
        }

        // Case 1: The array contains only zeros
        if (!has_nonzero) {
            return 0;
        }

        // Case 2: The total XOR is already non-zero, take the whole array
        if (total_xor != 0) {
            return nums.size();
        }

        // Case 3: Total XOR is 0, remove exactly 1 non-zero element
        return nums.size() - 1;
    }
};
