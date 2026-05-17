class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        map<int, int> past;
        int diff;
        for (int i = 0; i < nums.size(); i++)
        {
            if (past.find(nums[i]) == past.end())
                past.emplace (nums[i], i);
            diff = target - nums[i];
            if (past.find(diff) != past.end() && past[diff] != i)
            {
                output.push_back (past[diff]);
                output.push_back (i);
            }
        }
        return output;
    }
};
