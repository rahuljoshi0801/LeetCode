class Solution {
public:
    // long long dp[1002][1002];

    // long long solve(string &s, string &t, int m, int n) {

    //     // t is completely matched
    //     if (n == 0)
    //         return 1;

    //     // s is exhausted but t is still left
    //     if (m == 0)
    //         return 0;

    //     if (dp[m][n] != -1)
    //         return dp[m][n];

    //     if (s[m - 1] == t[n - 1]) {

    //         // Take s[m-1]
    //         // Don't take s[m-1]
    //         return dp[m][n] =
    //             solve(s, t, m - 1, n - 1) +
    //             solve(s, t, m - 1, n);

    //     } else {

    //         // Characters don't match, so skip s[m-1]
    //         return dp[m][n] =
    //             solve(s, t, m - 1, n);
    //     }
    // }

    // int numDistinct(string s, string t) {

    //     int m = s.length();
    //     int n = t.length();

    //     memset(dp, -1, sizeof(dp));

    //     return solve(s, t, m, n);
    // }
    typedef unsigned long long ull;

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<ull>> dp ( m+1 , vector<ull>(n+1 ,0));

        for( int i =0 ; i<= m ; i ++){
           dp[i][0] = 1 ; 
        }
        // for( int i =0 ; i<= n ; i ++){
        //    dp[0][i] = 0 ; 
        // }


        
        for (int i = 1; i <=m; i++) {
            for (int j = 1; j <= n; j++) {

                if (s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else  dp[i][j]  = dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};