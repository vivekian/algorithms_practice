#include <iostream> 
#include <vector>

using namespace std; 

void visit(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n)
{ 
    visited[i][j] = true; 

    if (j+1 < n && grid[i][j+1] == '1' && !visited[i][j+1]) 
        visit(grid, visited, i, j+1, m, n);

    if (i+1 < m && grid[i+1][j] == '1' && !visited[i+1][j]) 
        visit(grid, visited, i+1, j, m, n);
    
    if (j-1 >= 0 && grid[i][j-1] == '1' && !visited[i][j-1])
        visit(grid, visited, i, j-1, m, n); 
        
    if (i-1 >= 0 && grid[i-1][j] == '1' && !visited[i-1][j])
        visit(grid, visited, i-1, j, m, n); 
} 

int numIslands(vector<vector<char>>& grid) {
    const int numrows = grid.size(); 
    const int numcols = grid.empty() ? 0 : grid[0].size(); 

    int cnt = 0; 
    vector<vector<bool>> visited (numrows); 
    
    for (int i=0; i<numrows; ++i) { 
        visited[i].resize(numcols, false); 
    } 

    for (int i=0; i<numrows; ++i) { 
        for (int j=0; j<numcols; ++j) { 
            if (!visited[i][j] && grid[i][j] == '1') { 
                visit(grid, visited, i, j, numrows, numcols); 
                ++cnt; 
            } 
        } 
    }

    return cnt; 
}

int main() 
{
    vector<vector<char>> grid = 
    {{'1','1','1','1','0'},
     {'1','1','0','1','0'},
     {'1','1','0','0','0'},
     {'0','0','0','0','1'}}; 

    cout << numIslands(grid) << endl; 
    
    grid = {{}};
    cout << numIslands(grid) << endl;  
    
    grid = {{'1','0'}, {'0', '1'}}; 
    cout << numIslands(grid) << endl; 
    return 0; 
} 
