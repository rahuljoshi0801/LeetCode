class Solution {
public:
    int reverse(int x) {
        long long rev = 0;  // use long long to check overflow
        while (x != 0) {
            int lastnum = x % 10;
            rev = rev * 10 + lastnum;
            x /= 10;
        }
        // Check for 32-bit signed int overflow
        if (rev < INT_MIN || rev > INT_MAX) return 0;
        return (int)rev;
    }
};
