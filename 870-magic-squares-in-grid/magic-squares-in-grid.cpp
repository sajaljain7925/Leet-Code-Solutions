class Solution {
public:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        if (g[r+1][c+1] != 5) return false;

        vector<int> freq(10, 0);
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int v = g[i][j];
                if (v < 1 || v > 9) return false;
                if (++freq[v] > 1) return false;
            }
        }

        int s = 15;

        return
            g[r][c] + g[r][c+1] + g[r][c+2] == s &&
            g[r+1][c] + g[r+1][c+1] + g[r+1][c+2] == s &&
            g[r+2][c] + g[r+2][c+1] + g[r+2][c+2] == s &&

            g[r][c] + g[r+1][c] + g[r+2][c] == s &&
            g[r][c+1] + g[r+1][c+1] + g[r+2][c+1] == s &&
            g[r][c+2] + g[r+1][c+2] + g[r+2][c+2] == s &&

            g[r][c] + g[r+1][c+1] + g[r+2][c+2] == s &&
            g[r][c+2] + g[r+1][c+1] + g[r+2][c] == s;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < row; i++) {
            for (int j = 0; j + 2 < col; j++) {
                if (isMagic(grid, i, j)) count++;
            }
        }
        return count;
    }
};
