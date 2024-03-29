/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        s = stack<TreeNode*>();
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int result = s.top() -> val;
        TreeNode* temp = s.top(); s.pop();
        temp = temp->right;
        while (temp) {
            s.push(temp);
            temp = temp -> left;
        }
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

