class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //Create a hash map to store ints come across for easy lookup
        unordered_map <int, int> intsAppear;
        //loop through given vector
        for (int num : nums){
            //if find() comes up with the end, then does not appear, so add to hash map
            if (intsAppear.find(num) == intsAppear.end())
                intsAppear[num]=1;
            else
            //if any thing else besides end, then there is a repeat
                return true;
        }
        return false;
    }
};