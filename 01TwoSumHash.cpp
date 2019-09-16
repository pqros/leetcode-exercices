#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = m.find(target - nums[i]);
        if (it == m.end()) m[nums[i]] = i; else {
            return vector<int> {it->second ,i};
        }
    }
    return vector<int>();
}

int main(){
    vector<int> nums {2,5,5,11};
    vector<int> result = twoSum(nums, 10);
    for (auto& i : result){
        cout << i << endl;
    }
}