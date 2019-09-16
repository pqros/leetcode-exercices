#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string longestPalindrome(string s) {
    if (s.empty()) return "";
    stringstream ss;
    ss << '$';
    for (int i = 0; i < s.size(); ++i ) {
        ss << s[i] << "$";
    }
    s = ss.str();
    int n = s.size();
    int dp[n]; memset(dp, 0, sizeof(dp));
    int center = 0;
    int right = 0;
    int left = 0;
    for (int i = 0; i < n; ++i){
        if (i <= right) {
            int sym = 2 * center - i;
            if (sym - dp[sym] == center - dp[center]) {
                // case 2: left exactly till the end
                left = i - dp[sym];
                while (right + 1 < n && left - 1 >= 0 && s[right + 1] == s[left - 1]) {
                    ++right; --left;
                }
                center = i;
                dp[i] = right - i;
            } else {
                // case 3: left not till the ends 
                if (i + dp[sym] < right) dp[i] = dp[sym]; else {
                    // case 4: left stretches out
                    dp[i] = right - i;
                }
            }
        } else { 
            // case 1: current position is not covered
            left = right = center = i;
            while (right + 1 < n && left - 1 >= 0 && s[right + 1] == s[left - 1]) {
                ++right; --left;
            }
            center = i;
            dp[i] = right - i;
        }
        // cout << dp[i] << endl;
    }

    int result = 0;
    int mid = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > result) {
            result = dp[i];
            mid = i;
        }
    }
    ss = stringstream();
    for (int i = mid - dp[mid]; i <= mid + dp[mid]; ++i) {
        if (s[i] != '$') ss << s[i];
    }
    return ss.str();
}

int main() {
    string s = "a";
    cout << longestPalindrome(s) << endl;
}