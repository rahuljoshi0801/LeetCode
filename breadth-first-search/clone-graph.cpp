/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    void dfs(Node* node, Node* clone_node,unordered_map<Node*, Node*> &mp) {

        mp[node] = clone_node;
        for (Node* n : node->neighbors) {
            if (mp.find(n) == mp.end()) {
                Node* clone = new Node(n->val);
                clone_node->neighbors.push_back(clone);
                mp[n] = clone;
                dfs(n, clone,mp);
            } else {
                mp[n] = clone;
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return nullptr;
        Node* clone_node = new Node(node->val);

        mp.clear();

        mp[node] = clone_node;
       
        dfs(node, clone_node, mp);
        return  clone_node;
    }
};