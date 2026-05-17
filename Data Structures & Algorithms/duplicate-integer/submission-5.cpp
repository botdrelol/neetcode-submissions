class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //Create a hash table to store ints come across for easy lookup
        unordered_set <int> intsAppear;
        //loop through given vector
        for (int num : nums){
            //if num is already present, then return true
            if (intsAppear.count (num))
                return true;
            else
            //if not, add it
                intsAppear.insert(num);
        }
        return false;
    }
};