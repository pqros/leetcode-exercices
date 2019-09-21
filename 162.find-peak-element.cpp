/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
class Solution {
public:
    void helper(vector<int>& nums, int left, int right, int& result) {
        // printf("left = %d, right = %d\n", left, right);
        // < 5 nums
        if (right - left <= 3) {
            int i = left;
            while (i < right && nums[i] < nums[i + 1]) ++i;
            result = i; return;
        }
        int mid = (left + right)/2;
        if (nums[mid] < nums[left]) {
            helper(nums, left, mid - 1, result); 
            return;
        }
        if (nums[mid] < nums[right]) {
            helper(nums, mid + 1, right, result);
            return;
        }
        
        int lquart = (mid + left) / 2;
        if (nums[lquart] > nums[mid]) {helper(nums, left, mid - 1, result); return; }
        int rquart = (mid + right) / 2;
        if (nums[rquart] > nums[mid]) {helper(nums, mid + 1, right, result); return; }
        helper(nums, lquart + 1, rquart - 1, result);
    }

    int findPeakElement(vector<int>& nums) {
       int result;
       helper(nums, 0, nums.size() - 1, result);
       return result;
    }
};



