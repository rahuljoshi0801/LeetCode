/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res = 0 ;
    pair<int , int > solve (TreeNode* root ){
        if( root == NULL) return {0 ,  0} ; 
        pair<int, int> p1 = solve(root -> left ) ; 
        pair<int, int> p2 = solve( root -> right) ; 
        int totalSum = p1.first + p2.first + root-> val;
        int totalCount = p1.second + p2.second + 1;
        if(root-> val == totalSum/totalCount) res++ ; 

        return {totalSum,totalCount };
    }
    int averageOfSubtree(TreeNode* root) {
        solve(  root ) ; 
        return res ;
    }
};