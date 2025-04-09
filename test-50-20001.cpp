/*
Name: Beautiful Subgrids
Reference: https://cses.fi/problemset/task/2137

Input: The first input line has an integer n: the size of the grid.
Then there are n lines describing the grid: 1 means that a square is black and 0 means it is white.

Output: Print the number of beautiful subgrids.
Contributer: Rohan Mehra
git: rohmeh
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int count = 0;

    // Iterating over all pairs of rows (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Finding all columns where both grid[i][c] and grid[j][c] are '1'
            vector<int> validColumns;
            for (int c = 0; c < n; ++c) {
                if (grid[i][c] == '1' && grid[j][c] == '1') {
                    validColumns.push_back(c);
                }
            }

            int numValidColumns = validColumns.size();
            if (numValidColumns >= 2) {
                count += (numValidColumns) * (numValidColumns - 1) / 2;
            }
        }
    }

    cout << "20001\tDonald Knuth\t" << count << endl;
    return 0;
}