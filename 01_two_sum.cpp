#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag = 0;
        int tempsum;
        ListNode* res0 = new ListNode(0);
        ListNode* res = res0;
        while (l1 != NULL && l2 != NULL){
            tempsum = l1 -> val + l2 -> val + flag;
            if (tempsum >= 10){
                flag = 1;
                res -> next = new ListNode(tempsum - 10);
            }else{
                flag = 0;
                res -> next = new ListNode(tempsum);
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL){
            tempsum = l1 -> val + flag;
            if (tempsum >= 10){
                flag = 1;
                res -> next = new ListNode(tempsum - 10);
            }else{
                flag = 0;
                res -> next = new ListNode(tempsum);
            }
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            tempsum = l2 -> val + flag;
            if (tempsum >= 10){
                flag = 1;
                res -> next = new ListNode(tempsum - 10);
            }else{
                flag = 0;
                res -> next = new ListNode(tempsum);
            }
            l2 = l2 -> next;
        }     
        if (flag == 1) res -> next = new ListNode(1);
        return res0 -> next;
    }
};

int main(){
    Solution* a = new Solution();
    ListNode* b = new ListNode(3);
    b -> next = new ListNode(4);
    b -> next = new ListNode(2);
    ListNode* c = new ListNode(4);
    c -> next = new ListNode(6);
    c -> next = new ListNode(5);
    ListNode* d = a -> addTwoNumbers(b, c);
    cout << d -> val << endl;
}