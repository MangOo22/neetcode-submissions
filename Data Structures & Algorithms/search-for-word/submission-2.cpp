class Solution {

    bool dfs(int i, int j, int curSize, vector<vector<char>>& board, string word) {
        if (curSize == word.size()) { return true;}

        if (i >= board.size() or i < 0 or j >= board[0].size() or j < 0
            || board[i][j] != word[curSize] || board[i][j] == '#') { return false;}

        board[i][j] = '#';
        bool res = 
            dfs(i, j + 1, curSize + 1, board, word) ||
            dfs(i, j - 1, curSize + 1, board, word) ||
            dfs(i - 1, j, curSize + 1, board, word) ||
            dfs(i + 1, j, curSize + 1, board, word);
        board[i][j] = word[curSize];

        return res;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

