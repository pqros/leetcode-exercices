/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.80%)
 * Likes:    2851
 * Dislikes: 187
 * Total Accepted:    440.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// #include <iostream>
// #include <vector>
// #include <queue>
// #include "ListNode.cpp"
// using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        if (lists.size() == 1) return lists[0];
        auto compare = [&] (int& i, int &j){
            return lists[i] -> val > lists[j] -> val;
        };
        priority_queue<int, vector<int>, decltype(compare)> q(compare);
        // init
        for(int i = 0; i < lists.size(); ++i) {
            if (lists[i]) q.push(i);
        }
        ListNode* head = new ListNode(0);
        ListNode* l = head;
        while (!q.empty()) {
            int i = q.top();
            q.pop();
            l -> next = new ListNode(lists[i]->val);
            l = l -> next;
            lists[i] = lists[i] -> next;
            if(lists[i]) q.push(i);
        }
        return head -> next;
    }
};

