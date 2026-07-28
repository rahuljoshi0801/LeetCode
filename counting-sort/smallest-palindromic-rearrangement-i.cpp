class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n==1) return s;
        string u= s.substr(0,n/2);
        sort(u.begin(),u.end());
        string v = u;
        sort(v.rbegin(), v.rend());
        if(n%2==0){
            return u + v;
        }
        else{
            return u +s[(n/2)] + v;   
        }
    }
};