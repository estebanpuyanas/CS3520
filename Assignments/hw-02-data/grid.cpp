#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    const string prompt = "Enter row and column:";
    const unsigned int grid_size = 5;
    vector<vector<bool>> grid;
    
    // Initialize grid via resize method to use grid_size.
    grid.resize(grid_size, vector<bool>(grid_size, false));
    
    while (true) {
        unsigned int row, col;
        
        cout << prompt << "\n";  // Newline after prompt
        
        // Try to read row and column
        if (!(cin >> row >> col)) {
            // Display grid on input error. Use i,j as unsigned int to match grid_size otherwise leads to error. 
            for (unsigned int i = 0; i < grid_size; i++) {
                for (unsigned int j = 0; j < grid_size; j++) {
                    cout << (grid[i][j] ? 'X' : '.');
                }
                cout << "\n";
            }
            return 0;
        }
        
        // Check if coordinates are in range
        if (row >= grid_size || col >= grid_size) {
            // Display grid if out of range error. 
            for (unsigned int i = 0; i < grid_size; i++) {
                for (unsigned int j = 0; j < grid_size; j++) {
                    cout << (grid[i][j] ? 'X' : '.');
                }
                cout << "\n";
            }
            return 0;
        }
        
        // Place piece
        grid[row][col] = true;
        
        // Clear any remaining input on the line, for some reason this needs single over double quotes?
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Success. 
    return 0;
}