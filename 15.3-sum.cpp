class Solution {
public:
    void twoSum(vector<int>& nums, vector<vector<int> >& result, int start, int first) {
        if (start >= nums.size() - 1) return;
        int sum = -first;
        int i = start;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == sum) {
                result.push_back(vector<int>{first, nums[i], nums[j]});
                while (i < j && nums[i] == nums[i+1] ) ++i; ++i;
                while (i < j && nums[j] == nums[j-1] ) --j; --j;
            }
            else if (nums[i] + nums[j] < sum) {
                while (i < j && nums[i] == nums[i+1] ) ++i; ++i;
            }
            else {
                while (i < j && nums[j] == nums[j-1] ) --j; --j;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        if (nums.size() < 3) return result;
        for (int i = 0; i < nums.size() - 2; ++i) {
            twoSum(nums, result, i + 1, nums[i]);
            while(i < nums.size() - 1 && nums[i] == nums[i+1]) ++i;
        }
        return result;
    }
};