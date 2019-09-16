/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (31.76%)
 * Likes:    2705
 * Dislikes: 181
 * Total Accepted:    269K
 * Total Submissions: 846.1K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */
#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int a[256]; memset(a, 0, sizeof(a));
        int cnt = 0;
        for(auto& c : t) {
            if(!a[c]) {++cnt;}
            --a[c];
        }
        int left = 0;
        int minlen = 0x7fffffff;
        int minleft = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (!(++a[s[i]])) --cnt;
            // cout << cnt << endl;
            if (!cnt) {
                // printf("i = %d, left = %d, minlen = %d\n", i, left, minlen);
                while(a[s[left]] > 0){
                    --a[s[left]];
                    ++left;
                }
                if (i - left + 1 < minlen) {
                    minlen = i - left + 1;
                    minleft = left;
                }
            }
        }
        if (cnt) return "";
        return s.substr(minleft, minlen); 
    }
};

