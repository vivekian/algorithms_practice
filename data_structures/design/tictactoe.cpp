#include <iostream> 
#include <vector> 

using namespace std; 

class TicTacToe {
private: 
	vector<vector<int>> grid; 
	int num; 
	
	bool haswon(int r, int c, int p) { 
		bool res = true; 

		// check row 
		for (int col = 0; col < num; ++col) { 
			if (grid[r][col] != p) { 
				res = false; 
				break; 
			}
		} 
		
		if (res) { return res; } 
		res = true; 

		// check column
		for (int row = 0; row < num; ++row) { 
			if (grid[row][c] != p) { 
				res = false; 
				break; 
			}
		}

		if (res) { return res; } 

		// check right downward diagnol 
		if (r == c) { 
		    res = true;  
			for (int i=0; i<num; ++i) { 
				if (grid[i][i] != p) { 
					res = false; 
					break; 
				} 
			} 
		} 
	
		if (res) { return res; } 	
		res = true; 
		// check left diagnol 
		int row = num-1; 
		int col = 0; 

		while (row >= 0 && col < num) { 
			if (grid[row][col] != p) { 
				res = false; 
				break; 
			} 
			++col; 
			--row; 
		} 

		return res; 
	}
			
		
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
		num = n; 
        grid.resize(n); 
		
		for (int i=0; i<n; ++i) { 
			grid[i].resize(n); 
			fill(grid[i].begin(), grid[i].end(), 0); 
		} 
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        grid[row][col] = player; 
		
		if (haswon(row, col, player)) { 
			return player; 
		} 

		return 0; 		
    }
};

int main()
{ 
	return 0; 
} 
