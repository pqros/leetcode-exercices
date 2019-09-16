/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void swap(vector<int>& a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    void merge(vector<int>& nums, vector<int>& index, vector<int>& count, int begin, int end){
        if (begin == end) return;
        int mid = (begin + end)/2;
        merge(nums, index, count, begin, mid);
        merge(nums, index, count, mid+1, end);
        // merge
        
        // make a copy
        int n = end - begin + 1;
        int temp_nums[n];
        int temp_index[n];
        int i = begin, j = mid + 1, cursor = 0;
        while (i <= mid && j <= end) {
            if (nums[i] < nums[j]) {
                // printf("Inversion found: %d, %d\n", i, j);
                count[index[j]] += mid - i + 1;
                temp_nums[cursor] = nums[j];
                temp_index[cursor++] = index[j++];
            } else {
                temp_nums[cursor] = nums[i];
                temp_index[cursor++] = index[i++];
            }
        }
        while (i <= mid) {
            temp_nums[cursor] = nums[i];
            temp_index[cursor++] = index[i++];
        }
        while (j <= end) {
            temp_nums[cursor] = nums[j];
            temp_index[cursor++] = index[j++];
        }
        cursor = 0;
        for (int i = begin; i <= end; ++i) {
            nums[i] = temp_nums[cursor];
            index[i] = temp_index[cursor++];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        vector<int> index(n, 0);
        vector<int> count(n, 0);
        for(int i = 0; i < n; ++i) index[i] = i;
        merge(nums, index, count, 0, n - 1);
        reverse(count.begin(), count.end());
        return count;
    }
};
