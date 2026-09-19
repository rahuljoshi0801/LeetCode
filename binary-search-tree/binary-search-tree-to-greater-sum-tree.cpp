class Solution {
public:
    int sum = 0;

    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        // Visit larger values first
        solve(root->right);

        sum += root->val;
        root->val = sum;

        // Then smaller values
        solve(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        solve(root);
        return root;
    }
};