#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class gameOfLife {
   public:
    void solve(vector<vector<int>>& board) {
        vector<vector<int>> info(board);
        int h = board.size(), l = board[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                info[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                if (board[i][j] == 1) {
                    for (int a = 0; a < 3; a++) {
                        for (int b = 0; b < 3; b++) {
                            auto x = i - 1 + a;
                            auto y = j - 1 + b;
                            if (x < 0 || y < 0 || x >= h || y >= l) {
                                continue;
                            }
                            if (x == i && y == j) {
                                continue;
                            }
                            info[x][y] += 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                if (board[i][j] == 1) {
                    switch (info[i][j]) {
                        case 2:
                        case 3:
                            break;
                        default:
                            board[i][j] = 0;
                    }
                } else {
                    if (info[i][j] == 3) {
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};