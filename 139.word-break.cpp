/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
class Solution {
public:
    bool helper(string& s, vector<string>& wordDict, int pos, bool vis[]) {
        int l = s.size() - pos;
        if (!l) return true;
        for (auto& word : wordDict) {
            if (word.size() <= l) {
                int j = 0;
                while (j < word.size() && word[j] == s[pos + j]) ++j;
                if (j == word.size() && !vis[pos + word.size()]) {
                    vis[pos + word.size()] = true;
                    if (helper(s, wordDict, pos + word.size(), vis)) return true;
                } 
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (wordDict.empty()) return false;
        int pos = 0;
        bool vis[s.size()+1]; memset(vis, false, sizeof(vis));
        return helper(s, wordDict, pos, vis);
    }
};
