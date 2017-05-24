/* Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
 * The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
 * Note that you can only put the bomb at an empty cell.
 *
 * Example:
 * For the given grid
 *
 * 0 E 0 0
 * E 0 W E
 * 0 E 0 0
 *
 * return 3. (Placing a bomb at (1,1) kills 3 enemies) */ 

#include <iostream> 
#include <vector> 

using namespace std; 

int maxKilledEnemies(vector<vector<char>>& grid) {
	if (grid.empty() || grid[0].empty()) { 
        return 0; 
    } 
    
    const int num_rows = grid.size();
    const int num_cols = grid[0].size();
   
    int rowenemies[num_rows][num_cols];
    int colenemies[num_rows][num_cols];

	for (int i=0; i<num_rows; ++i) {
			for (int j=0; j<num_cols; ++j) {
					rowenemies[i][j] = 0;
					colenemies[i][j] = 0;
			}
	}

    for (int i=0; i<num_rows; ++i) {
        int num_enemies = 0, start = 0;

		// count the number of enemies till a wall is hit
        for (int j=0; j<num_cols; ++j) {

			if (grid[i][j] == 'E') {
				num_enemies++;
			}
			// once the wall is hit, update the number of enemies on each empty cell 
			else if (grid[i][j] == 'W') {
                for (int k=start; k<j; ++k) {
                	if (grid[i][k] == '0') {
                            rowenemies[i][k] = num_enemies;
                    }
                }

                num_enemies = 0;
                start = j+1;
            }
        }

		// update the number of enemies for each empty cell. 
		for (int k=start; k<num_cols; ++k) {
			if (grid[i][k] == '0')
				rowenemies[i][k] = num_enemies;
		}
    }

    for (int j=0; j<num_cols; ++j) {
        int num_enemies = 0;
        int start = 0;

        for (int i=0; i<num_rows; ++i) {
            if (grid[i][j] == 'E') {
                ++num_enemies;
            }
            else if (grid[i][j] == 'W') {
                for (int k=start; k<i; ++k) {
                    if (grid[k][j] == '0')
       		             colenemies[k][j] = num_enemies;
                }

                num_enemies = 0;
                start = i+1;
            }
        }

		for (int k=start; k<num_rows; ++k) {
			if (grid[k][j] == '0')
				colenemies[k][j] = num_enemies;
		}
    }

    int max_enemies = 0;

    // find the number of enemies on the row, col and update the max. 
	for (int i=0; i<num_rows; ++i) {
        for (int j=0; j<num_cols; ++j) {
            int curr_max = rowenemies[i][j] + colenemies[i][j];
             
            if (curr_max > max_enemies) {
                max_enemies = curr_max;
            }
        }
    }

    return max_enemies;
}

int main()
{ 
	vector<vector<char>> grid = {{ '0', 'E', '0','0'},
								 { 'E', '0', 'W','E'},
								 { '0', 'E', '0','0'}}; 

	cout << maxKilledEnemies(grid) << endl; 	 
} 
