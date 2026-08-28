class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> v(26);
        for (char& ch : s) {
            v[ch - '0']++;
        }
        int cant = 0;
        for (char& ch : s) {
            if (v[ch] % 2 != 0) {
                cant++;
            }
        }
        if (cant % 2 != 0)
            return "";
    }
};