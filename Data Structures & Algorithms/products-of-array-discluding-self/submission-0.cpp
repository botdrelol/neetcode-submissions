class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector <int> result (size);
        //to the left of i
        vector<int> prefix (size);
        prefix[0] = 1;
        //to the right of i
        vector <int> suffix (size);  
        suffix[size-1] = 1;
        for (int i =1; i <= size-1; i++)
            prefix[i] = nums[i-1] * prefix[i-1];
        for (int i = size -2; i >= 0; i--)
            suffix[i] = nums[i+1] * suffix[i+1];
        for (int i = 0; i < size; i++)
        {
            result[i] = prefix[i] * suffix[i];        
        }
        return result;
    }
};
