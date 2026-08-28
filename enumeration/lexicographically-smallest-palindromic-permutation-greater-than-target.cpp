class Solution {
public:
    char mid = '$';
    int halflen = 0;
    string res = "";
    bool solve(string curr, vector<int>& v, string target, int i, bool greater) {
        if (curr.length() == halflen) {
            string candidate = curr;
            string rightHalf = curr;
            reverse(begin(rightHalf), end(rightHalf));//right half

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
        vector<int> v(26);
        int n = s.length();
        
        for (char& ch : s) {
            v[ch - 'a']++;
        }
        int cant = 0, flag = 0;
        for (char& ch : s) {
            if (v[ch - 'a'] % 2 != 0) {
                cant++;
                if (cant == 1 && flag == 0) {
                    mid = ch;
                    flag = 1;
                }
            }
        }
        if (cant > 1)
            return "";

        string curr = ""; // left half
        halflen = n / 2;
        solve(curr, v, target, 0, false);
        return res;
    }
};