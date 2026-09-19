class Solution {
public:
    vector<int> result;
    vector<int> prefixSum;
    int n;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        result.push_back(root->val);
        inorder(root->right);
    }

    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        solve(root->left);

        // Find this node's position in inorder
        int index = lower_bound(result.begin(), result.end(), root->val) - result.begin();

        root->val = prefixSum[n - 1] - (index > 0 ? prefixSum[index - 1] : 0);

        solve(root->right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        // Step 1: Inorder traversal
        inorder(root);

        n = result.size();

        // Step 2: Prefix sum
        prefixSum.resize(n);

        prefixSum[0] = result[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = result[i] + prefixSum[i - 1];
        }

        // Step 3: Update tree
        solve(root);

        return root;
    }
};