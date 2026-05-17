class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, bool> check;
        for (int num : nums)
        {
            if (check.count(num))
                return true;
            check.emplace (num, true);
        }
        return false;
    }
};