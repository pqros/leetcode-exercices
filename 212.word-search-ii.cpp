/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
class Solution {
public:
    struct TrieNode {
        TrieNode* next[26];
        string word;
        TrieNode() : next(), word() {}
    };

    void dfs(vector<vector<char>>& board, TrieNode* root, int i, int j, vector<string>& result){
        if (board[i][j] == '#' || !root->next[board[i][j] - 'a']) return;
        root = root->next[board[i][j] - 'a'];
        if (!(root->word).empty()) {
            result.push_back(root->word);
            root->word = "";
        }
        char temp = board[i][j];
        board[i][j] = '#';
        if (i > 0) dfs(board, root, i - 1, j, result);
        if (i < board.size() - 1) dfs(board, root, i + 1, j, result);
        if (j > 0) dfs(board, root, i, j - 1, result);
        if (j < board[0].size() - 1) dfs(board, root, i, j + 1, result);
        board[i][j] = temp;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty()) return vector<string>();

        // init trie
        TrieNode* root = new TrieNode();
        for(auto& word : words) {
            TrieNode* iter = root;
            for(auto& letter : word) {
                if (!(iter -> next[letter - 'a']))
                    iter->next[letter-'a'] = new TrieNode();
                iter = iter->next[letter-'a'];   
            }
            iter->word = word;
        }

        // dfs
        vector<string> result;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                dfs(board, root, i, j, result);

        return result;
    }
};

