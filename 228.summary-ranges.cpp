/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        long curr;
        int count = 0;
        
        for(auto& num : nums) {
            if (!count || num == curr + 1) {
                curr = num; ++count;
            } else {
                ostringstream ss;
                if (count == 1) {
                    ss << curr; 
                } else {
                    ss << curr - count + 1 << "->" << curr;
                }
                result.push_back(ss.str());
                count = 1;
                curr = num;
            }
        }
        ostringstream ss;
        if (count == 1) {
            ss << curr; 
        } else {
            ss << curr - count + 1 << "->" << curr;
        }
        result.push_back(ss.str());
        return result;      
    }
};

