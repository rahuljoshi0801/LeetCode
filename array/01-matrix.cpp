/*class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
        // <coordinates, steps>
	    queue<pair<pair<int,int>, int>> q; 
	    // traverse the matrix
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 0
	            if(mat[i][j] == 0) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }

    }
    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1};
     while ( !q.empty()){
        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
        q.pop();
        dist[row][col] = steps; 

        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 

    }

};*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int INF = m + n; // A safe maximum possible distance
        
        // Pass 1: Check Top and Left neighbors (Top-Left to Bottom-Right sweep)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                
                int top = INF, left = INF;
                if (i - 1 >= 0) top = mat[i - 1][j];
                if (j - 1 >= 0) left = mat[i][j - 1];
                
                mat[i][j] = min(top, left) + 1;
            }
        }
        
        // Pass 2: Check Bottom and Right neighbors (Bottom-Right to Top-Left sweep)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 0) continue;
                
                int bottom = INF, right = INF;
                if (i + 1 < m) bottom = mat[i + 1][j];
                if (j + 1 < n) right = mat[i][j + 1];
                
                // Compare the current value (from Pass 1) with the bottom/right options
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        
        return mat;
    }
};