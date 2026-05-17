class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l =0;
        int r = numbers.size() -1;

        while (l < r)
        {
            //move r pointer down until smaller
            // if (numbers[r] > target)
            //     r--;
            int tempTotal = numbers[l] + numbers[r];
            if (tempTotal < target)
                l++;
            else if (tempTotal > target)
                r--;
            else
                return {l + 1, r +1};            
        }
        return {0};
    }
};
