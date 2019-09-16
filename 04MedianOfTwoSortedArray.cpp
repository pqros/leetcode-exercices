#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size();
    int n2 = nums2.size();

    if (nums1.empty()) {
        if (n2 & 1) return nums2[n2/2];
        else return 0.5 * (nums2[n2/2-1] + nums2[n2/2]);
    }

    if (nums2.empty()) {
        if (n1 & 1) return nums2[n1/2];
        else return 0.5 * (nums2[n1/2-1] + nums2[n1/2]);
    }

    // Goal find (n1 + n2)/2
    int nl = (n1 + n2)/2;
    int nl1 = n1/2;
    int nl2 = nl - nl1;
    int l1, l2, r1, r2;
    int lmin = 0, lmax = n1;
    while (true) {
        cout << nl1 << ' ' << nl2 << endl;
        int l1 = (!nl1) ? INT_MIN : nums1[nl1-1];
        int l2 = (!nl2) ? INT_MIN : nums2[nl2-1];
        int r1 = (nl1 == n1) ? INT_MAX : nums1[nl1];
        int r2 = (nl2 == n2) ? INT_MAX : nums2[nl2];
        if (l1 <= r2 && l2 <= r1) {
            if ((n1 + n2) & 1){
                return 1.0 * min(r1, r2);
            } else {
                return 0.5 * (max(l1, l2) + min(r1, r2));
            }
        }
        if (l1 < r2) lmin = nl1 + 1;
        else lmax = nl1 - 1;
        nl1 = (lmax + lmin) / 2;
        nl2 = nl - nl1;
    }

    return 0;
}

int main(){
    vector<int> nums1 {
        1, 2, 3, 6, 7
    };
    vector<int> nums2 {
        4, 5, 8, 9, 10
    };
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}