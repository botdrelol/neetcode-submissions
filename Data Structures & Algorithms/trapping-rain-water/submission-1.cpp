class Solution {
public:
    int trap(vector<int>& height) {
        int area=0;
        int cap = height.size();
        if (height.size()==0)
            return 0;
        vector<int> leftMax (cap);
        vector<int> rightMax(cap);

        //starting from the left, go to the right and see what is the highest wall from leftside at a given element
        leftMax[0]= height[0];
        for (int i =1; i < cap;i++)
            leftMax[i] = max(leftMax[i-1] , height[i]);
        
        //starting from the right, go to the left and see what is the highest wall from the right side at a given element
        rightMax [cap-1] = height[cap-1];
        for (int i = cap-2; i >= 0; i--)
            rightMax[i] = max(rightMax[i+1], height[i]);
        
        //at a given element, the amount of water held is the minimum between the two highest walls on either side of an element
        for (int i = 0; i <cap; i++)
            area += ((min(leftMax[i], rightMax[i])) - height[i]);
        return area;
    }
};
