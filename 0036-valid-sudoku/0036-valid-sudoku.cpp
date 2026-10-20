class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < m; j += 3) {
                unordered_map<char, int> map;
                for (int a = i; a < i + 3; a++) {
                    for (int b = j; b < j + 3; b++) {
                        if (board[a][b] != '.') {
                            map[board[a][b]]++;
                        }
                    }
                }
                for (auto& it : map) {
                    if (it.second > 1) {
                        return false;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> map;
            for (int j = 0; j < m; j++) {
                if (board[i][j] != '.') {
                    map[board[i][j]]++;
                }
            }
            for (auto& it : map) {
                if (it.second > 1) {
                    return false;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            unordered_map<char, int> map;
            for (int j = 0; j < n; j++) {
                if (board[j][i] != '.') {
                    map[board[j][i]]++;
                }
            }
            for (auto& it : map) {
                if (it.second > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
