class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> right(n + 1, 0);
        vector<int> seq;

        int i = n - 1;
        int j = m - 1;

        while (i >= 0) {
            if (j>=0 && word1[i] == word2[j]) {
                right[i] = 1 + right[i + 1];
                
                j--;
            } else {
                right[i] = right[i + 1];
                
            }
            i--;
        }

        bool canchange = true;
        i = 0, j = 0;

        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                
                j++;
            } else if (canchange && i+1<n && right[i + 1] >= m - j - 1) {
                seq.push_back(i);
                
                j++;
                canchange = false;
            }
            i++;
        }
        
        return j==m? seq : vector<int> ();
    }
};