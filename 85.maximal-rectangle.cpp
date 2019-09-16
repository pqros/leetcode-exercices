/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (34.39%)
 * Likes:    1680
 * Dislikes: 54
 * Total Accepted:    133.6K
 * Total Submissions: 388.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int largestRectangleArea(vector<int> &h) {  
        stack<int> S;  
        h.push_back(0);  
        int sum = 0;  
        for (int i = 0; i < h.size(); i++) {  
            if (S.empty() || h[i] > h[S.top()]) S.push(i);  
            else {  
                int tmp = S.top();  
                S.pop();  

                // we can insert i -> every number before i is smaller
                sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));  
                i--;  
            }  
       }  
       return sum;  
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<int> h = vector<int>(matrix[0].size(), 0);
        int maxarea = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j)
                h[j] = matrix[i][j] == '1' ? h[j] + 1 : 0;
            maxarea = max(maxarea, largestRectangleArea(h));
        }
        return maxarea;
    }
};

