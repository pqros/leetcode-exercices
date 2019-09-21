/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* iter = root;
        while (iter) {
            s.push(iter);
            iter = iter -> left;
        }
        int result;
        while (k--) {
            iter = s.top(); result = iter->val; s.pop();
            iter = iter -> right;
            while (iter) {
                s.push(iter);
                iter = iter -> left;
            }
        }
        return result;
    }
};

