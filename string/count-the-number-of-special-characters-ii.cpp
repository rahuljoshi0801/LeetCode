class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> small(26, -1);
        vector<int> large(26,-1);
        for (int i=0;i<word.length();i++){
            char ch = word[i];
            if (islower(ch)){
                small[ch-'a']=i;

            }
            else
                if(large[ch-'A']==-1)
                    large[ch-'A']=i;
        }
        int count =0 ; 
        for (int i =0 ; i<word.length();i++){
            if(small[i]!=-1&&large[i]!=-1 && large[i]>small[i]){
                count ++;
            }
        }
        return count ;
    }
};