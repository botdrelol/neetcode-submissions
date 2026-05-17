class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target, l, r, temp;
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            l = i + 1;
            r = nums.size() - 1;
            target = -1 * nums[i];
            while (l < r)
            {
                temp = nums[l] + nums[r];
                if (temp == target)
                {
                    output.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                }
                else if (temp < target)
                    l++;
                else if (temp > target)
                    r--;
            }
        }
        return output;
    }
};
