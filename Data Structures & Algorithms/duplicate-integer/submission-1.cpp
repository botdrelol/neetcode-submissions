class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //keep hashmap to see what values have been looked at
        unordered_map <int, bool> check;
        for (int num : nums)
        {
            // if value is in hashamp = seen before
	        //     return true
            if (check.count(num))
                return true;
            // if value not in hashmap = not seen before
	        // add to hashmap and continue
            check.emplace (num, true);
        }
        return false;
    }
};