/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // partie entier
        if (!numerator) return "0";
        ostringstream result;
        if (numerator > 0 ^ denominator > 0) result << "-";
        long la = (numerator > 0) ? numerator : (-1)*(long)numerator;
        long lb = (denominator > 0) ? denominator : (-1)*(long)denominator;
        long q = la/lb;
        long res = la%lb;
        result << q;
        if (!res) return result.str();
        result << '.';

        vector<long> digits;
        unordered_map<long, int> m;
        int flag = 0;

        while (res) {
            res *= 10;
            q = res/lb;
            res %= lb;
            digits.push_back(q);
            if (m[res]) {
                flag = m[res];
                break;
            }
            m[res] = digits.size();
        }

        if (!flag) {
            for (auto& digit : digits) result << digit;
        } else {
            for (int i = 0; i < flag; ++i) {
                result << digits[i];
            }
            result << "(";
            for (int i = flag; i < digits.size(); ++i) {
                result << digits[i];
            }
            result << ")";
        }
        return result.str();
    }
};

// example
// 25 / 24 -> 1 1 
// 10 / 24 -> 0 10 m[10] = 1
// 100 / 24 -> 4 4 m[4] = 2
// 40 / 24 -> 1 16 m[16] = 3
// 160 / 24 -> 6 16 m[16] = 3 -> print 1.041(6)

