class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int bigL =0;
        int bigR = matrix.size()-1;
        //binary search the rows/the vector of vectors
        while (bigL <= bigR){
            int mid = bigL + ((bigR-bigL)/2);
            int n = matrix[mid].size();
            //get the least and greatest ints from the middle value
            int bottom = matrix[mid][0];
            int top = matrix[mid][n-1];
            
            //target lies in this range, binary search this row
            if (bottom <= target && target <= top){
                int smallL = 0;
                int smallR = n;
                //binary search of the individual row
                while (smallL <= smallR){
                    int smallM = smallL + ((smallR- smallL)/2);
                    //target lies above mid, search upper half
                    if (target > matrix[mid][smallM])
                        smallL = smallM +1;
                    //target lies below mid, search lower half
                    else if (target < matrix[mid][smallM])
                        smallR = smallM -1;
                    //found target
                    else
                        return true;
                }
                return false;
            }

            //target lies below range, search lower rows
            else if (bottom > target)
                bigR = mid-1;
            //target lies above range, serach upper rows
            else if (top < target)
                bigL = mid + 1;       
        }
        return false;
    }
};
