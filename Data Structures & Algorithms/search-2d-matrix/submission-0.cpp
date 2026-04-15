class Solution {
private:
    bool findTarget(vector<vector<int>> &mat, int tar) {
        int rows = mat.size();
        int cols = mat[0].size();

        // find the target row
        int l = 0, r = rows - 1;
        int catchRow = -1;
        while(l <= r) {
            int row = l + (r - l) / 2;
            if (tar > mat[row].back()) {
                l = row + 1;
            } else if (tar < mat[row][0]) {
                r = row - 1;
            } else {
                catchRow = row;
                break;
            }
        }
        // check if there is row catched 
        if (catchRow == -1) {
            return false;
        }
        // find the target col
        catchRow = l + (r - l) / 2;
        l = 0, r = cols - 1;
        while(l <= r) {
            int col = l + (r - l) / 2;
            if (tar > mat[catchRow][col]) {
                l = col + 1;
            } else if (tar < mat[catchRow][col]) {
                r = col - 1;
            } else {
                return true;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       return findTarget(matrix, target);
    }
};