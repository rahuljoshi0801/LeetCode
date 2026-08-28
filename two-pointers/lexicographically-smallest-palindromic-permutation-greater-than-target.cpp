class Solution {
public:
    char mid = '$';
    int halflen = 0;
    string res = "";
    bool solve(string curr, vector<int>& v, string target, int i,
               bool greater) {
        // for palandromic string
        if (curr.length() == halflen) {
            string candidate = curr;
            string rightHalf = curr;
            reverse(begin(rightHalf), end(rightHalf)); // right half

            if (mid != '$') {
                candidate += mid;
            }
            candidate += rightHalf;
            if (candidate > target) {
                res = candidate;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (v[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i]) {
                continue;
            }
            // Do
            curr.push_back(ch);
            v[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, v, target, i + 1, isGreater)) {
                return true;
            }
            // undo
            curr.pop_back();
            v[ch - 'a']++;
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> v(26, 0);
        int n = s.length();

        for (char& ch : s) {
            v[ch - 'a']++;
        }
        int cant = 0, flag = 0;
        for (int c = 0; c < 26; c++) {
            if (v[c] % 2 == 1) { 
                cant++; 
                mid = c + 'a'; 
            }
        }
        if (cant > 1)
            return "";

        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = v[c] / 2;
        }

        string curr = ""; // left half

        halflen = n / 2;

        solve(curr, halfCount, target, 0, false);
        return res;
    }
};