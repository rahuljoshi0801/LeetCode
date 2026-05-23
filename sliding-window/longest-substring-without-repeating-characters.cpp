class Solution {
public:

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        // If duplicate found, shrink window from left
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
        }
        // Add current character
        charSet.insert(s[right]);
        // Update maximum length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

};