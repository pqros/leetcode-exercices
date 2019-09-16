/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.19%)
 * Likes:    2203
 * Dislikes: 100
 * Total Accepted:    211.8K
 * Total Submissions: 808K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;

        int maxlen = 0;
        int q = 2;
        int curr;
        int cnt;
        int lastzero;
        char sign[2]; sign[0] = '('; sign[1] = ')';

        while(q--) {
            cnt = 0;
            curr = -1;
            lastzero = 0;
            for(int i = 0; i < s.size(); ++i) {
                cnt += (s[i] == sign[q]) ? -1 : 1;
                if (!cnt) {
                    maxlen = max(maxlen, i - curr);
                } else if (cnt < 0) {
                    cnt = 0;
                    curr = i;
                }
            }
            if (q) reverse(s.begin(), s.end());
            // printf("current: %d\n", maxlen);
        }
        return maxlen;
    }
};

// int main () {
//     Solution sol;
//     string s = "(";
//     sol.longestValidParentheses(s);
// }
