#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int index[nums.size()];
    for (int i = 0; i < nums.size(); ++i) index[i] = i;
    sort(
        index, index + nums.size(), [&](int a, int b) -> bool {
            return nums[a] < nums[b];
        }
    );
    int left = 0;
    int right = nums.size() - 1;
    while (nums[index[left]] + nums[index[right]] != target){
        if (nums[index[left]] + nums[index[right]] > target)
            --right;
        else
            ++left;
    }
    vector<int> result {index[left], index[right]};
    return result;
}

int main(){
    vector<int> nums {2,5,5,11};
    vector<int> result = twoSum(nums, 10);
    for (auto& i : result){
        cout << i << endl;
    }
}