class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> prev;
        int diff;
        for (int i = 0 ; i < nums.size(); i++){
            //input nums + index for quick lookup
            if (prev.find(nums[i]) == prev.end())
                prev[nums[i]] =i;
            //find the difference
            diff = target - nums[i];
            //if difference is present in hast table and is not the current index
            if ((prev.find(diff) != prev.end()) && (prev[diff] != i)){
                return {prev[diff], i};
            }
        }
        return {0};
    }
};
