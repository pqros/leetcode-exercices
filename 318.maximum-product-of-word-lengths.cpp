/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.size() <= 1) return 0;
        int result = 0;
        long a[words.size()]; memset(a, 0, sizeof(a));
        
        for(int i = 0; i < words.size(); ++i) 
            for(auto& c : words[i]) 
                a[i] |= (1 << (c - 'a'));
            
        for(int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (!(a[i] & a[j])) result = max(result, (int)(words[i].size() * words[j].size()));
            }
        }
        
        return result;
    }
};