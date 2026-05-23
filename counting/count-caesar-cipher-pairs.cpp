class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string ,int > rp;
        long long  count = 0 ; 
        for ( const string& word : words ){
            string normalized( word.length(), 'a');
            int shift = word[0] - 'a';

            for ( int i = 0 ; i< word.length();i++ ){
                normalized[i] = 'a' + (word[i] - 'a' - shift + 26) % 26;
            }

            count += rp[normalized];
            rp[normalized]++;
            }
        
        return count ;
    }
};