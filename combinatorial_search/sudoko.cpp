#include <iostream> 
using namespace std; 

typedef struct Grid 
{ 
	int cells[9][9]; 
} Grid; 

bool IsValid(Grid& grid, const int Row, const int Col, int val)
{
	if (val == 0) 
		return true;  

	for (int row = 0; row < 9; ++row)
		if ((val == grid.cells[row][Col]) && (row != Row))
			return false; 

	for (int col = 0; col < 9; ++col)  
		if ((val == grid.cells[Row][col]) && (col != Col)) 
			return false; 

	int startr = Row - (Row%3); 
	int startc = Col - (Col%3); 

	for (int i = startr; i < (startr + 3); ++i) 
		for (int j = startc; j < (startc + 3); ++j) 
			if (val == grid.cells[i][j] && (i != Row) && (j != Col)) 
				return false; 

	return true; 
} 

bool GetNextCell(Grid& grid, int& row, int& col) 
{ 
	for (int i = 0; i < 9; ++i) { 
		for (int j = 0; j < 9; ++j) {  
			if(grid.cells[i][j] == 0) { 
			 	row = i; 
				col = j;
				return true;  
			} 
		} 
	} 

	return false; 
} 

void PrintGrid(Grid& grid) 
{ 
	for (int i = 0; i < 9; ++i) { 
		for (int j = 0; j < 9; ++j) { 
			cout << grid.cells[i][j] << " "; 
		} 
		cout << endl; 
	} 
} 

bool SolveSudoko(Grid& grid) 
{
	int row, col; 

	// no empty cells left, you are done! 
	if (!GetNextCell(grid, row, col)) 
		return true; 
	
	// try from 1 to 9, as long as its valid, solve recursively further 
	// future steps will determine if previous steps were correct or not 
	// if you fail, jump back and try another number. 
	for (int i = 1; i < 10; ++i) { 
		if (IsValid(grid, row, col, i)) { 
			grid.cells[row][col] = i; 
			if (SolveSudoko(grid)) 
				return true; 
			grid.cells[row][col] = 0; 
		} 
	} 
	 
	return false;  
}

int main() 
{
	Grid grid; 

	for (int i = 0; i < 9; ++i) 
		for (int j = 0; j < 9; ++j) 
			grid.cells[i][j] = 0; 
	
	grid.cells[0][3] = 4; 
	grid.cells[0][5] = 8; 
	
	grid.cells[1][4] = 3; 
	grid.cells[1][6] = 2; 
	grid.cells[1][7] = 1; 

	grid.cells[2][1] = 2; 
	grid.cells[2][4] = 1; 
	grid.cells[2][7] = 5; 
	grid.cells[2][8] = 3;

	grid.cells[3][2] = 6; 
	grid.cells[3][3] = 2; 
	grid.cells[3][6] = 1; 
	grid.cells[3][7] = 8; 
	grid.cells[3][8] = 7; 
	
	grid.cells[4][0] = 2; 
	grid.cells[4][2] = 8; 
	grid.cells[4][3] = 6; 
	grid.cells[4][5] = 1; 
	grid.cells[4][6] = 3; 
	grid.cells[4][8] = 5; 
	
	grid.cells[5][0] = 7; 
	grid.cells[5][1] = 5; 
	grid.cells[5][2] = 1; 
	grid.cells[5][5] = 9; 
	grid.cells[5][6] = 6; 
		
	grid.cells[6][0] = 1; 
	grid.cells[6][1] = 3; 
	grid.cells[6][4] = 4; 
	grid.cells[6][7] = 7;
		
	grid.cells[7][1] = 8; 
	grid.cells[7][2] = 2; 
	grid.cells[7][4] = 9; 
 
	grid.cells[8][3] = 8; 
	grid.cells[8][5] = 3;

	PrintGrid(grid);
	
	for (int i = 0; i < 9; ++i) { 
		for (int j = 0; j < 9; ++j) { 
			if (!IsValid(grid, i, j, grid.cells[i][j])) { 
				cerr << "Invalid Sudoko!" << endl; 
			} 
		} 
	} 
	
	cout << "Sudoko is valid" << endl; 	
 
	if (SolveSudoko(grid)) 
		cout << "SUCCESS" << endl; 
	else 
		cout << "FAILURE" << endl;  
	
	PrintGrid(grid); 
	
	for (int i = 0; i < 9; ++i) { 
		for (int j = 0; j < 9; ++j) { 
			if (!IsValid(grid, i, j, grid.cells[i][j])) { 
				cerr << "Invalid Sudoko!" << endl; 
			} 
		} 
	}
} 
