/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */
class Solution {
public:
    void helper(TreeNode* root, string curr, vector<string>& result) {
        curr += "->" + to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(curr);
            return;
        }
        if (root->left) helper(root->left, curr, result);
        if (root->right) helper(root->right, curr, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        string curr = to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(curr);
            return result;
        }
        if (root->left) helper (root->left, curr, result);
        if (root->right) helper (root->right, curr, result);
        return result;
    }
};

