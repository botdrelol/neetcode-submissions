class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> prev;
        int diff;
        for (int i = 0 ; i < nums.size(); i++){
            if (prev.find(nums[i]) == prev.end())
                prev[nums[i]] =i;
            diff = target - nums[i];
            if (prev.find(diff) != prev.end() && prev[diff] != i){
                return {prev[diff], prev[nums[i]]};
            }
        }
    }
};
