class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        auto dfs = [&](auto&& self, int i, int j, int k) -> bool {
            if (k == word.size()) return true;
            if (i < 0 || j < 0 || i >= m || j >= n ||
                board[i][j] != word[k]) return false;

            char c = board[i][j];
            board[i][j] = '#';

            bool found = self(self, i + 1, j, k + 1) ||
                         self(self, i - 1, j, k + 1) ||
                         self(self, i, j + 1, k + 1) ||
                         self(self, i, j - 1, k + 1);

            board[i][j] = c;
            return found;
        };

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(dfs, i, j, 0)) return true;

        return false;
    }
};