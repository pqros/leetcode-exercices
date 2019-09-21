/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:

    // kmp
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
        string s2 = s;
        reverse(s2.begin(), s2.end());
        string t = s + '#' + s2;       
        int kmp[t.size()]; memset(kmp, 0, sizeof(kmp));
        for (int i = 1; i < t.size(); ++i) {
            int j = kmp[i-1];
            while (t[i] != t[j] && j) j = kmp[j - 1];
            if (t[i] == t[j]) kmp[i] = j + 1;
        }
        // return "";
        return s2.substr(0, s2.size() - kmp[t.size() - 1]) + s;
    }
};

