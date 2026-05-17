class Solution {
public:
    int maxArea(vector<int>& heights) {
        int length, l, r, area, temp, height;
        area = 0;
        for (int i =0; i < heights.size()-1; i++)
        {
            l = i;
            r = heights.size() -1;
            while (l < r)
            {
                //create area of rectangle with edges l and r
                height = min (heights[l], heights[r]);
                length = r-l;
                temp = height * length;
                area = max (temp, area);
                //l is higher, so change the lower r
                if (heights[l] > heights[r])
                    r--;
                else
                //r is higher, so change the lower l
                    l++;
                
            }
        }
        return area;
    }
};
