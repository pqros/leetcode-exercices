/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // save answers to subquestions
    unordered_map<string, vector<string>> m;


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (m.count(s)) return m[s];
        vector<string> result;
        for (auto& word : wordDict) if (s == word) {result.push_back(s); break;}

        // subproblems
        for (int i = 1; i < s.size(); ++i) {
            // look for the suffix
            string suffix = s.substr(i);
            int flag = false;
            for (auto& word : wordDict) if (suffix == word) {flag = true; break;}
            if (flag) {
                vector<string> preWordBreak = wordBreak(s.substr(0, i), wordDict);
                for(auto& split : preWordBreak) {
                    split = split + " " + suffix;
                }
                result.insert(result.end(), preWordBreak.begin(), preWordBreak.end());            
            }
        }
        
        // Key: memory!
        m[s] = result;
        return result;
    }
};

