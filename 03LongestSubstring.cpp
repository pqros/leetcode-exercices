#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;
    int maxlen = 0;
    int start = 0;
    unordered_map <char, int> m;
    
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (m.find(c) == m.end() || m[c] < start) {
            m[c] = i;
            continue;
        }

        maxlen = max(maxlen, i - start);
        start = m[c] + 1;
        m[c] = i;
    }

    maxlen = max(maxlen, (int)s.size() - start);
    return maxlen;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
}