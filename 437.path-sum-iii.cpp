/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (43.55%)
 * Likes:    2128
 * Dislikes: 119
 * Total Accepted:    120.9K
 * Total Submissions: 277.6K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// # include <iostream>
// # include <unordered_map>
// # include "TreeNode.cpp"
// using namespace std;

class Solution {
public:
    void dfs(unordered_map<int, int>& m, TreeNode* root, int curr, int& sum, int& count) {
        if (!root) return;
        curr += root->val;
        count += m[curr - sum];
        if (m.find(curr) == m.end()) {
            m[curr] = 1;
        } else {
            m[curr] += 1;
        }
        dfs(m, root->left, curr, sum, count);
        dfs(m, root->right, curr, sum, count);
        --m[curr];
    }

    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        int count = 0;
        dfs(m, root, 0, sum, count);
        return count;
    }


};

