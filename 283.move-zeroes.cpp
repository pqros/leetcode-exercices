/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.03%)
 * Likes:    2317
 * Dislikes: 83
 * Total Accepted:    516.4K
 * Total Submissions: 938.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int k = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                nums[k++] = nums[i];
            }
        }
        for (int i = k; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};

