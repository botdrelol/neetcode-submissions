class Solution {
public:
    int trap(vector<int>& height) {
        int area=0;
        int cap = height.size();
        if (height.size()==0)
            return 0;
        vector<int> leftMax (cap);
        vector<int> rightMax(cap);

        leftMax[0]= height[0];
        for (int i =1; i < cap;i++)
            leftMax[i] = max(leftMax[i-1] , height[i]);
        
        rightMax [cap-1] = height[cap-1];
        for (int i = cap-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        
        for (int i = 0; i <cap; i++)
            area += ((min(leftMax[i], rightMax[i])) - height[i]);
        return area;
    }
};
