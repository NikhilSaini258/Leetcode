class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> xAxis (matrix.size(), 0);   // To store X-Axis having zero
        vector<int> yAxis (matrix[0].size(), 0);    // To store Y-Axis having zero
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    xAxis[i] = 1;
                    yAxis[j] = 1;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (xAxis[i] || yAxis[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};

// Space Optimized -> Use Array row0 and column0 for storing X-Axis and Y-Axis zero
// https://takeuforward.org/data-structure/set-matrix-zero/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j == 0) {
                        col0 = 0;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
