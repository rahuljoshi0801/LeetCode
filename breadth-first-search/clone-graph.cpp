class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* dfs(Node* node) {
        // Already cloned
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create clone
        Node* clone = new Node(node->val);
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        mp.clear();
        return dfs(node);
    }
};