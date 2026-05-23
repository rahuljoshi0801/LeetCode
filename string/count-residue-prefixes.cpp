class Solution {
public:
    int residuePrefixes(string s) {
        int freq[26]={0}; int distinct =0 ; int count =0;
        for (int i = 0; s[i] != '\0'; i++){
            int idx = s[i]-'a';

            if(freq[idx]==0){
                distinct++;
            }

            freq[idx]++;

            if (distinct == (i+1)%3 )count ++ ; 

        }
        return count ; 


        
    }
};