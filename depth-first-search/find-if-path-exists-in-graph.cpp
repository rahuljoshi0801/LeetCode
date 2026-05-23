class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        unordered_map<int, vector<int>> mp;

        // build graph
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        queue<int> q;
        vector<int> visited(n, 0);

        q.push(source);
        visited[source] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination) return true;

            for(int nei : mp[node]){
                if(!visited[nei]){
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }

        return false;
    }
};