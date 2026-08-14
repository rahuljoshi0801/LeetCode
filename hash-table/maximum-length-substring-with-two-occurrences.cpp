class Solution {
public:
    unordered_map<char, int> freq;
    int len = 0;
    int maximumLengthSubstring(string s) {
        int i = 0, j = 0;
        int n = s.length();
        
        while (j < n) {
            freq[s[j]]++;
            while (freq[s[j]] >2) {
                freq[s[i]]--;
                i++;

            } 
                j++;
                
            
            len = max(len, j - i + 1);
        }
        return len;
    }
};