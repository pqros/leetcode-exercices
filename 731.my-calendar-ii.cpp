/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

class MyCalendarTwo {
public:
    map <int, int> count;
    MyCalendarTwo() {
        count = map<int, int>();
    }
    
    bool book(int start, int end) {
        // cout << "new book" << endl;
        count[start] = count[start] ? count[start] + 1 : 1;
        count[end] = count[end] ? count[end] - 1 : -1;
        int flag = 0;
        for (auto it = count.begin(); it != count.end(); ++it) {
            // if (!it->second) {count.erase(it); continue;}
            // printf("%d, %d\n", it->first, it->second);
            flag += it->second;
            if (flag > 2) {
                --count[start]; if(!count[start]) count.erase(start);
                ++count[end]; if(!count[end]) count.erase(end);
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

