/*
id: 22011356
name: Rithish Hari
contact: +60182030508
email: rithish_22011356@utp.edu.
lab: 2 medium
*/

#include <iostream>
#include <vector>

using namespace std;

void fill(vector<vector<int>>& grid, int r, int c, int original, int target) {
    int height = grid.size();
    int width = grid[0].size();

    if (r < 0 || r >= height || c < 0 || c >= width || grid[r][c] != original)
        return;

    grid[r][c] = target;

    fill(grid, r + 1, c, original, target);
    fill(grid, r - 1, c, original, target);
    fill(grid, r, c + 1, original, target);
    fill(grid, r, c - 1, original, target);
}

vector<vector<int>> applyFloodFill(vector<vector<int>> image, int row, int col, int color) {
    if (image.empty()) return image;

    int originalColor = image[row][col];
    if (originalColor != color) {
        fill(image, row, col, originalColor, color);
    }

    return image;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row)
            cout << val << " ";
        cout << '\n';
    }
}

int main() {
    vector<vector<int>> image = {
        {1, 1, 1, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 1}
    };

    int startRow = 1;
    int startCol = 2;
    int newColor = 2;

    auto updatedImage = applyFloodFill(image, startRow, startCol, newColor);

    printGrid(updatedImage);

    return 0;
}