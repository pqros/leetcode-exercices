/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int cnt[26];
        bool in_result[26]; memset(in_result, false, sizeof(in_result));
        string result;
        for (auto& c : s) {
            ++cnt[c - 'a'];
        }
        for (auto& c : s) {
            --cnt[c - 'a'];
            // keep 1 copy of every letter
            if (in_result[c - 'a']) continue;
            // we pop the last element if
            // it's greater than the current & there're more left
            while (!result.empty() && c < result.back() && cnt[result.back() - 'a']) {
                in_result[result.back() - 'a'] = false;
                result.pop_back();
            }
            in_result[c - 'a'] = true;
            result.push_back(c);
        }
        return result;
    }
};

