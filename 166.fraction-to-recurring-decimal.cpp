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
        long nlong = numerator;
        long dlong = denominator;
        unordered_map<long, int> m;
        vector<long> test;
        long res = nlong % dlong;
        test.push_back(nlong/dlong);
        int flag = 0;
        while (res) {
            if(m[res]) {
                flag = m[res];
                break;
            }
            m[res] = test.size();
            test.push_back((10*res)/dlong); 
            res = (10*res) % dlong;
        }

        ostringstream ss;
        ss << test[0] << ".";
        if (!flag) {
            for(int i = 1; i < test.size(); ++i) {
                ss << test[i];
            }
        } else {
            for(int i = 1; i < flag; ++i) {
                ss << test[i];
            }
            ss << '(';
            for(int i = flag; i < test.size(); ++i) {
                ss << test[i];
            }
            ss << ')';
        }
        return ss.str();
    }
};
