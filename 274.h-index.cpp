/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = citations.size() - 1;
        while(i >= 0 && citations[i] > citations.size() - i) --i;
        if (i < 0) {
            return citations.size();
        } else {
            return max(citations[i], (int)citations.size() - 1 - i);
        }
    }
};

