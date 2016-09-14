#include <iostream> 
#include <vector> 

using std::vector; 
using std::ostream; 

class NQueens 
{
    public:  
        NQueens(const int n): num(n) { 
            board.resize(num); 

            for (auto& row: board) { 
                row.resize(num); 
            }
        }

        // write solution to ostream. Q for queen, . if empty. 
        void write(ostream& os);

        // solve the nqueens problem using backtracking  
        void solve(); 

    private:
        // check if queen is in non-attacking position 
        bool is_queen_non_attacking(int r, int c);     
       
        // try placing queen in different colomn positions for a given row
        // and if successful, try the next row, else backtrack.  
        bool solve_row(int r);
        
        // clear the board  
        void clear(); 
         
        vector<vector<bool>> board; 
        int num; 
};  
