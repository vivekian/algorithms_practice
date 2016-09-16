#include <string> 
#include "nqueens.h" 

using std::endl; 
using std::string; 

void NQueens::write(ostream& os)
{ 
     for (const auto & row: board) { 
        for(const auto & col: row) { 
            string s = (col == true) ? "Q": "."; 
            os << s; 
        }
        os << endl; 
    }

    os << endl;  
} 

bool NQueens::is_queen_non_attacking(int r, int c) 
{
//     std::cout << "check " << r << " " << c << endl;  
    // check vertical  
    for (int i=0; i<r; ++i) { 
        if (board[i][c]) { 
            return false; 
        } 
    } 

    // check horizontal
    for (int i=0; i<c; ++i) { 
        if (board[r][i]) { 
            return false; 
        } 
    } 

    // check right diagonal 
    int i = r-1; 
    int j = c-1; 

    while (i>=0 && j>=0)  { 
        if (board[i][j]) { 
            return false; 
        } 
        i--; 
        j--; 
    } 

    // check left diaganol 
    i = r-1; 
    j = c+1; 

    while (i>=0 && j<num) { 
        if (board[i][j]) { 
            return false; 
        } 
        i--; 
        j++; 
    } 

    return true; 
} 

bool NQueens::solve_row(int row) 
{
    // all rows are solved at this point and we terminate  
    if (row == num) { 
        return true; 
    } 

    // for a given row, try each column till non-atttacking position is possible
    for (int j=0; j<num; ++j) {

        if (is_queen_non_attacking(row, j)) { 

            board[row][j] = true; 

            // solve the next row and if solved, return true
            if (solve_row(row+1)) { 
                return true; 
            } 

            // backtracking: if the next row was not solvable, then set your entry to false 
            // and try with the next column entry 
            board[row][j] = false; 
        }
    } 

    return false; 
}  

void NQueens::clear() 
{ 
    for (auto& row: board) { 
        std::fill(row.begin(), row.end(), false); 
    } 
}

void NQueens::solve()
{ 
    // for the first row, try each column. if successful, 
    // then print the solution, clear the board and try 
    // next column. 
    for (int j=0; j<num; ++j) { 
     
        board[0][j] = true; 

        if (solve_row(1)) { 
            write(std::cout); 
        } 

        clear(); 
    } 
} 

int main() 
{
    int n; 
    std::cin >> n;  
    
    NQueens nq(n); 
    nq.solve(); 

    return 0; 
} 
