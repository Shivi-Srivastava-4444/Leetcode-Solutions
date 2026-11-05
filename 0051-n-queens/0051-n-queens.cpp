class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> col, diag1, diag2;
    int n;

    void solve(int r) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = r - c + n - 1;
            int d2 = r + c;

            if (col[c] || diag1[d1] || diag2[d2])
                continue;

            board[r][c] = 'Q';
            col[c] = diag1[d1] = diag2[d2] = true;

            solve(r + 1);

            board[r][c] = '.';
            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        board.assign(n, string(n, '.'));
        col.assign(n, false);
        diag1.assign(2 * n - 1, false);
        diag2.assign(2 * n - 1, false);

        solve(0);
        return ans;
    }
};