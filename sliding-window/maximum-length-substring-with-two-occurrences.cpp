class Solution {
public:
    unordered_map<char, int> freq;
    int len = 0;
    int maximumLengthSubstring(string s) {
        int i = 0, j = 0;
        int n = s.length();
        freq[s[i]] = 1;
        while (j < n) {

            if (freq[s[j]] >= 2) {
                freq[s[i]]--;
                i++;
                
            } else {
                j++;
                freq[s[j]]++;
            }
            len = max(len, j - i + 1);
            
        }
        return len;
    }
};