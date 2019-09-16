#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* h = new ListNode(0);
    ListNode* head = h;
    int flag = 0;
    while (l1 && l2) {
        int sum = l1->val + l2->val + flag;
        if (sum >= 10) {
            sum -= 10;
            flag = 1;
        } else {
            flag = 0;
        }

        head -> next = new ListNode(sum);
        head = head -> next;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        int sum = l1->val + flag;
        if (sum >= 10) {
            sum -= 10;
            flag = 1;
        } else {
            flag = 0;
        }

        head -> next = new ListNode(sum);
        head = head -> next;
        l1 = l1->next;
    }
    while (l2) {
        int sum = l2->val + flag;
        if (sum >= 10) {
            sum -= 10;
            flag = 1;
        } else {
            flag = 0;
        }

        head -> next = new ListNode(sum);
        head = head -> next;
        l2 = l2->next;
    }

    if (flag) head -> next = new ListNode(1);

    return h -> next;
}

int main() {

}