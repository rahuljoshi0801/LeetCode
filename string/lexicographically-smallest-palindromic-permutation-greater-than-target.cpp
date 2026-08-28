class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> v(26);
        for (char& ch : s) {
            v[ch - 'a']++;
        }
        int cant = 0;
        for (char& ch : s) {
            if (v[ch- 'a'] % 2 != 0) {
                cant++;
            }
        }
        if (cant != 1)
            return "";
        return "a";
    }
};