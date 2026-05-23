class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
    int m =grid.size();
    int n =grid[0].size();
    // for time
    int days = 0;

    // Variable to store total number of oranges (fresh + rotten)
    int tot = 0;

    // Variable to count how many oranges became rotten during the process
    int cnt = 0;

    queue<pair<int, int>> rotten;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            
            // If the cell is not empty (has fresh or rotten orange)
            if (grid[i][j] != 0)
                tot++; // Count it as a valid orange

            // If it's a rotten orange, add its position to the queue
            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }
    // Arrays to explore the 4 directions: right, left, down, up
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while(!rotten.empty()){
        int k = rotten.size();
        cnt += k;

        while(k--){
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for(int i=0;i<4;i++){
            int nx = x + dx[i]; // New x-coordinate
            int ny = y + dy[i]; // New y-coordinate

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1)
                    continue;
            grid[nx][ny] = 2;
            
            rotten.push({nx, ny});
            }
        }
        if (!rotten.empty())
            days++;
    

    }
    return tot == cnt ? days : -1;

    }
};