class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> leftSide (size, -1);
        vector<int> rightSide (size, size);
        stack<int> currI; 

        //iterate through heights
        //as each height is checked from left to right
        //check if curr height is < current lowest height
        //pop until no lower height on stack, then push i onto stack and leftSide
        //at index i of heights, the leftSide vector has the lowest height to the left of it
        for (int i = 0; i < size; i++)
        {
            while (!currI.empty() && heights[currI.top()] >= heights[i])
                currI.pop();
            if (!currI.empty())
                leftSide[i] = currI.top();
            currI.push(i);
        }
        while(!currI.empty())
            currI.pop();
        //at index i of heights, the rightSide vector has the lowest height to the right of it
        for (int i = size-1; i >= 0; i--)
        {
            while (!currI.empty() && heights[currI.top()] >= heights[i])
                currI.pop();
            if (!currI.empty())
                rightSide[i] = currI.top();
            currI.push(i);
        }
        int maxArea =0;
        for (int i = 0; i < size; i ++)
        {
            leftSide[i] += 1;
            rightSide[i] -=1;
            maxArea = max(maxArea, heights[i] * (rightSide[i] - leftSide[i] +1));
        }
        return maxArea;

    }
};
