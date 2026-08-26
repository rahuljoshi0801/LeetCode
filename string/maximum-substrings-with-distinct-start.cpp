class Solution {
public:
    int maxDistinct(string s) {
        vector<int> taken(26, 0);
        int  count = 0;
        for (char &ch : s){
            if ( taken[ch - 'a']== 0 ){
                count++;
            }
        }
        return count ;

    }
};