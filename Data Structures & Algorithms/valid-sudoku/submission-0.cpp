class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int length = 9;
        for (int row = 0; row < length; row++)
        {
            unordered_set<char> rows;
            for (int col = 0; col < length; col++)
            {
                if (board[row][col] !='.')
                    if (rows.count(board[row][col]))
                        return false;
                rows.insert(board[row][col]);
            }
        }
        for (int col = 0; col < length; col++)
        {
            unordered_set<char> cols;
            for (int row = 0; row < length; row++)
            {
                if (board[row][col] !='.')
                    if (cols.count(board[row][col]))
                        return false;
                cols.insert(board[row][col]);
            }
        }
        for (int squares = 0; squares < length; squares++)
        {
            unordered_set<char> square;
            for (int row = 0; row < 3; row ++)
            {
                for (int col = 0; col < 3; col ++)
                {
                    int currRow = (squares/ 3) * 3 +row;
                    int currCol = (squares %3) * 3 + col;
                    if (board[currRow][currCol] !='.')
                        if (square.count(board[currRow][currCol]))
                            return false;
                    square.insert(board[currRow][currCol]);
                }
            }
        }

        return true;
    }
};
