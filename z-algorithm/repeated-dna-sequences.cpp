class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> result;

        int n = (int)s.length();  // ✅ cast to int — prevents unsigned underflow

        if (n < 10) return {};    // ✅ edge case: string too short

        for (int i = 0; i <= n - 10; i++) {
            string dna = s.substr(i, 10);
            if (seen.find(dna) != seen.end()) {
                result.insert(dna);
            }
            seen.insert(dna);
        }

        return vector<string>(result.begin(), result.end());
    }
};
