/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (32.09%)
 * Likes:    2240
 * Dislikes: 59
 * Total Accepted:    193.2K
 * Total Submissions: 601.5K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        heights.push_back(0);
        int a[heights.size()]; int asize = 0;
        stack<int> index;
        int maxarea = 0;
        for(int i = 0; i < heights.size(); ++i) {
            int leftmost = -1;
            while(!index.empty() && heights[index.top()] >= heights[i]) {
                maxarea = max(max((i-index.top())*heights[index.top()], (i-index.top()+1)*heights[i]), maxarea);
                leftmost = index.top();
                index.pop();
            }
            if(leftmost == -1) {
                index.push(i);
            } else {
                index.push(leftmost);
                heights[leftmost] = heights[i];
            }

            if(!index.empty() && heights[index.top()] == heights[i]) {
                maxarea = max(maxarea, (i-index.top()+1)*heights[i]);
            } else {
                index.push(i);
            }
            // printf("current i = %d, stack size = %d, maxarea = %d\n", i, (int)index.size(), maxarea);
        }
        return maxarea;
    }
};

// int main() {
//     vector<int> heights {2,1,2};
//     Solution sol;
//     cout << sol.largestRectangleArea(heights) << endl;
// }


