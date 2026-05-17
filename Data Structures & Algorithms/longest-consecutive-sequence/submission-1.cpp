class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> input;
        int count=0;
        int maxCount=0;
        for (int num : nums)
            input.insert(num);
        
        for (int num : nums)
        {
            int currNum = num;
            if (!(input.count(num-1)))
            {
                currNum ++;
                count ++;
                while (input.count(currNum))
                {
                    currNum ++;
                    count ++;
                }
            }
            if (maxCount < count)
                maxCount = count;
            count = 0;
        }
        return maxCount;
    }
};
