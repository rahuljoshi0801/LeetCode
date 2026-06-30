class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();//row

        int n = obstacleGrid[0].size();//column

        vector<vector<int>>dp ( n, vector<int>(m,-1));
        for ( int i =0; i<n;i++){
            for ( int j =0; j<m;j++){
                if (obstacleGrid[i][j] == 1) {
                    /* If there's an obstacle at the 
                    cell, no paths can pass through it*/
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0) {
                    /* If we are at the starting 
                    point, there is one path to it*/
                    dp[i][j] = 1;
                    continue;
                }
                int up = 0;
                int left = 0;
                /* Check if we can move up and left 
                (if not at the edge of the maze)*/
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];

                /* Total number of paths to reach (i, j)
                is the sum of paths from above and left*/
                dp[i][j] = up + left;
            }
        }
        /* The final result is stored in dp[m-1][n-1],
        which represents the destination*/
        return dp[m - 1][n - 1];

    }
};