/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 2 easy 
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateRight(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return {};

    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    vector<vector<int>> rotated(cols, vector<int>(rows));

    for (size_t row = 0; row < rows; ++row) {
        for (size_t col = 0; col < cols; ++col) {
            rotated[col][rows - row - 1] = matrix[row][col];
        }
    }

    return rotated;
}

void display(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            cout << val << " ";
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> input = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    vector<vector<int>> output = rotateRight(input);
    display(output);

    return 0;
}