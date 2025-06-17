/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 2 hard
*/

#include <iostream>
#include <vector>

using namespace std;

void applyBooleanMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> rowFlag(m, false);
    vector<bool> colFlag(n, false);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                rowFlag[i] = true;
                colFlag[j] = true;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (rowFlag[i] || colFlag[j]) {
                matrix[i][j] = 1;
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    applyBooleanMatrix(mat);
    printMatrix(mat);

    return 0;
}