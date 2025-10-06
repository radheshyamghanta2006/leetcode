class Solution {
public:
// Code with Radheshyam (.^.)
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        // 8 possible knight moves
        int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

        // The first cell must be visited first
        if (n == 0 || grid[0][0] != 0) return false;
        
        // Position array: pos[step] = {row, col}
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int step = grid[i][j];
                if (step < 0 || step >= n * n) return false; // optional bounds check
                pos[step] = {i, j};
            }
        }
        // Check if every consecutive move is a valid knight move
        for (int step = 0; step < n * n - 1; ++step) {
            int x1 = pos[step].first, y1 = pos[step].second;
            int x2 = pos[step + 1].first, y2 = pos[step + 1].second;

            bool validMove = false;
            for (int k = 0; k < 8; ++k) {
                if (x1 + dx[k] == x2 && y1 + dy[k] == y2) {
                    validMove = true;
                    break;
                }
            }
            if (!validMove) return false;
        }
        return true;
    }
};