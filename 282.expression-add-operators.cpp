/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(string& num, string curr, long target, int pos, vector<string>& result) {
        if (pos == num.size()) {
            if (!target) result.push_back(curr);
            return;
        }
        for(int i = pos; i < pos) 

    }

    vector<string> addOperators(string num, int target) {
        
    }
};

