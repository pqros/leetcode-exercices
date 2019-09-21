/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:

    void calc(stack<int>& nums, stack<char>& ops) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char c = ops.top(); ops.pop();
        switch (c) {
            case '+':
                nums.push(a + b);
                return;
            case '-':
                nums.push(a - b);
                return;
            case '*':
                nums.push(a * b);
                return;
            case '/':
                nums.push(a - b);
                return;
        }
    }

    int calculate(string s) {
        istringstream ss(s);
        int result;
        stack<char> ops;
        stack<int> nums;
        int num;
        char op;
        while (ss) {
            char op = ss.peek(); if (op == ' ') {ss >> ws; continue;}
            if (op >= '0' && op <= '9') {
                ss >> num; nums.push(num);
            } else {
                ss >> op;
                switch (op){
                    case '(':
                        ops.push(op);
                        break;
                    case ')':
                        while (ops.top() != '(') calc(nums, ops);
                        ops.pop();
                        break;
                    case '+':
                    case '-':
                        while (!ops.empty() && ops.top() != '(') calc(nums, ops);
                        ops.push(op);
                        break;
                    case '*':
                    case '/':
                        if (!ops.empty() && (ops.top() == '*' || ops.top() == '/')) calc(nums, ops);
                        ops.push(op);
                        break;
                }
            }
        }
        while (!ops.empty()) calc(nums, ops);
        return nums.top();
    }
};

