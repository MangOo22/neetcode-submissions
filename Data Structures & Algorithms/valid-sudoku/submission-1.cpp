class Solution {
public:bool isValidSudoku(vector<vector<char>>& board) {
  // each block represented by (r/3, c/3)
  bool rows[9][9] = {0}, cols[9][9] = {0};
  bool boxs[9][9][9] = {0};
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') continue;
      int num = board[i][j] - '0' - 1;
      if (rows[i][num] or cols[j][num] or boxs[i/3][j/3][num]) {
        return false;
      }
      rows[i][num]= cols[j][num] = boxs[i/3][j/3][num] = true;
    }
  }
  return true;
}
};
