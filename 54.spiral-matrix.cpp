/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        // 0 right, 1 down, 2 left 3 up
        int m = matrix.size(), n = matrix[0].size();
        int index[] = {1, 0, 1, 0};
        int step[] ={1, 1, -1, -1};
        int lim[] = {n-1, m-1, 0, 0};
        int mode = 0;
        int cnt = m*n;
        int pos[2] = {0, 0};

        while(cnt--) {
            result.push_back(matrix[pos[0]][pos[1]]);
            if (pos[index[mode]] == lim[mode]) {
                lim[(mode + 3) % 4] -= step[(mode + 3) % 4];
                mode = (mode + 1) % 4;
            }
            pos[index[mode]] += step[mode];
        }

        return result;
    }
};

