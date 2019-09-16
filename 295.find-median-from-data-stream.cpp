/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (38.25%)
 * Likes:    1389
 * Dislikes: 27
 * Total Accepted:    125.3K
 * Total Submissions: 327.3K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> big;
    priority_queue<int> small;

    bool eq_flag;

    MedianFinder() {
        eq_flag = true;
    }
    
    void addNum(int num) {
        if (eq_flag) { // insert left
            if (big.empty() || num <= big.top()) small.push(num);
            else {
                small.push(big.top());
                big.pop();
                big.push(num);
            }
        } else { // insert right
            if (small.empty() || num >= small.top()) big.push(num);
            else {
                big.push(small.top());
                small.pop();
                small.push(num);
            }
        }
        eq_flag = !eq_flag;
    }
    
    double findMedian() {
        if (eq_flag && big.empty()) return 0;
        if (eq_flag) return 0.5*(small.top() + big.top());
        else return small.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

