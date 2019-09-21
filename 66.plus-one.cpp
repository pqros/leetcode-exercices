/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr = digits.size() - 1;
        while (curr >= 0) {
            if (digits[curr] == 9) {
                digits[curr--] = 0;
            } else {
                ++digits[curr];
                return digits;
            }
        }
        if (curr < 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

