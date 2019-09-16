#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    bool dp[n+1]; memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= m; ++i) {
        dp[0] = true;
        for (int j = 1; i <= n; ++j) {
            if (p[j-1] == '*') {
                dp[j] = 0;
            }
        }
    }
}