class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target, l, r, temp;
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            //skip over any repeating numbers
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            //starting from the right of i and the end
            l = i + 1;
            r = nums.size() - 1;
            //i+j+k = 0 -> j+k = -i
            //find negative i in array
            target = -1 * nums[i];
            while (l < r)
            {
                temp = nums[l] + nums[r];
                if (temp == target)
                {
                    output.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    //keep skipping past duplicate numbers 
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
