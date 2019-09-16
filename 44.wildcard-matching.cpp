/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        dp[0][0] = 1;
        for(int j = 1; j <= p.size(); ++j) {
            dp[0][j] = dp[0][j-1] && p[j-1] == '*';
        }
        for(int i = 1; i <= s.size(); ++i) {
            dp[i][0] = false;
        }

        for(int i = 1; i <= s.size(); ++i) {
            for(int j = 1; j <= p.size(); ++j) {
                dp[i][j] = (dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?' || p[j-1] == '*')) || (dp[i-1][j] && p[j-1] == '*') || (dp[i][j-1] && p[j-1] == '*');
            }
        }
        return dp[s.size()][p.size()];
    }
};

