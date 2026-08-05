class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int ans =0;
        for(int i =n-1; i>=0;i--){
            if(s[i]==" ") continue;
            if ( s[i] == "-") ans = -1*ans;
            if ( s[i] == "+") break ;
            


        }
    }
};