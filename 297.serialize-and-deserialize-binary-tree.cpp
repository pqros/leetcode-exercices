/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream ss;
        queue<TreeNode*> q;
        if (!root) return "";
        q.push(root);
        while(!q.empty()) {
            // cout << "s " << q.size() << endl;
            TreeNode* curr = q.front();
            q.pop();
            if (curr) {
                ss << " " << curr->val; 
                q.push(curr->left);
                q.push(curr->right);
            }
            else ss << " $";
        }
        ss << " &";
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        istringstream ss(data);
        int root_val; ss >> root_val; TreeNode* root = new TreeNode(root_val); 
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()) {
            // cout << "d " << q.size() << endl;
            // cout << ss.str() << endl;
            int i;

            ss >> ws;
            char c = ss.peek();
            if (c == '&') return root;
            // read left & right;
            TreeNode* curr = q.front(); q.pop();
            if (c == '$') {
                ss >> c;
            } else {
                ss >> i; curr -> left = new TreeNode(i); q.push(curr -> left);
            }

            ss >> ws;
            c = ss.peek();
            if (c == '&') return root;
            if (c == '$') {
                ss >> c;
            } else {
                ss >> i; curr -> right = new TreeNode(i); q.push(curr -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));