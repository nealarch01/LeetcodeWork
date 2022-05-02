class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        // There must be at least 5 moves (3 x and 2 o) is the least option
        if (moves.size() < 5) {
            return "Pending";
        }
        char grid[3][3] = {
            {' ', ' ', ' '}, 
            {' ', ' ', ' '}, 
            {' ', ' ', ' '}
        };
        for (int i = 0; i < moves.size(); i++) {
            int x = moves[i][0];
            int y = moves[i][1];
            grid[x][y] = (i % 2 == 0) ? 'x' : 'o';
        }

        // Find first letter
        // For loop will traverse the outer array aka row
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // If slot is empty, skip to the next iteration
                // Otherwise, check diagonal, then do horizontal and vertical test
                if (grid[i][j] != ' ') {
                    if (i == j) { // Diagonal case
                        // Diagonal top left -> right
                        if (grid[0][0] == 'x' && grid[1][1] == 'x' && grid[2][2] == 'x') return "A";
                        if (grid[0][0] == 'o' && grid[1][1] == 'o' && grid[2][2] == 'o') return "B";
                        
                        if (grid[2][0] == 'x' && grid[1][1] == 'x' && grid[0][2] == 'x') return "A";
                        if (grid[2][0] == 'o' && grid[1][1] == 'o' && grid[0][2] == 'o') return "B";
                    } else { // Not diagonal case
                        // Horizontal check current row i index 
                        if (grid[i][0] == 'x' && grid[i][1] == 'x' && grid[i][2] == 'x') return "A";
                        if (grid[i][0] == 'o' && grid[i][1] == 'o' && grid[i][2] == 'o') return "B";
                        
                        // Vertical check current column j index
                        if (grid[0][j] == 'x' && grid[1][j] == 'x' && grid[2][j] == 'x') return "A";
                        if (grid[0][j] == 'o' && grid[1][j] == 'o' && grid[2][j] == 'o') return "B";
                    }
                } 
            } // End of j loop
        } // End of i loop
        if (moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
}; // End of class
