class Solution {
    public:
        vector<vector<string>> solutions;
        vector<vector<char>> grid;
        
        bool canPlace(int row, int col, int n) {
            // Check column
            for (int i = row - 1; i >= 0; i--) {
                if (grid[i][col] == 'Q') return false;
            }
            // Check left diagonal
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (grid[i][j] == 'Q') return false;
            }
            // Check right diagonal
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (grid[i][j] == 'Q') return false;
            }
            return true;
        }
    
        void f(int row, int n) {
            if (row == n) {
                vector<string> board;
                for (int i = 0; i < n; i++) {
                    board.push_back(string(grid[i].begin(), grid[i].end()));
                }
                solutions.push_back(board);
                return;
            }
    
            for (int col = 0; col < n; col++) {
                if (canPlace(row, col, n)) {
                    grid[row][col] = 'Q';
                    f(row + 1, n);
                    grid[row][col] = '.';
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            grid.assign(n, vector<char>(n, '.'));
            solutions.clear();
            f(0, n);
            return solutions;
        }
    };