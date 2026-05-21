class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0; 
        int r = nums.size()-1;

        while (l <= r){
            //find middle index
            int mid = l + ((r-l)/2);
            //check lower half by moving right bound below mid
            if (nums[mid] > target)
                r = mid -1;
            //check upper half by moving left bound above mid
            else if (nums[mid] < target)
                l = mid + 1;
            //that means found target
            else
                return mid;
        }
        return -1;
    }
};
