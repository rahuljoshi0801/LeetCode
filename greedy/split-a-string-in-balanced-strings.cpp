class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0 , l = 0;
        int count = 0;
        int n = s.length();
        for ( int i = 0 ; i <n ; i++){
            if(s[i] == 'R') r++;
            else l++;

            if(r == l){ r =0 , l =0; count++; }
        }
        return count ;
    }
};