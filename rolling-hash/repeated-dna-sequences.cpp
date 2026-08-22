class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> result;

        for (int i = 0; i <= s.length() - 10; i++) {  // ✅ <= not 
            string dna = s.substr(i, 10);              // ✅ length = 10
            if (seen.find(dna) != seen.end()) {
                result.insert(dna);
            }
            seen.insert(dna);
        }

        return vector<string>(result.begin(), result.end());
    }
};