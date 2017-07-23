#include <iostream> 
#include <vector> 
#include <string> 
#include <queue> 

using namespace std; 

namespace {
        struct Loc {
                int x;
                int y;
        };
}

class SnakeGame {
    private:
		// grid to map if items are Food or Snake itself. 
		// to space save, could just remember a set of snake chars.
        vector<vector<char>> grid;
	
		// queue of directions which the snake followed. 
		// these are popped off as we make progress. 
        queue<char> q;

		// pointer to food pairs 
        vector<pair<int, int>>::iterator fp;
        int w=0; int h=0;
        vector<pair<int, int>> f;
		
		// head of the snake, tail of the snake. 
        Loc head = {0,0}; 
        Loc tail = {0,0};

public:
   SnakeGame(int width, int height, vector<pair<int, int>> food):
                        w(width), h(height), f(food)
   {
        fp = f.begin();
        grid.resize(height);

        for (int i=0; i<grid.size(); ++i) {
            grid[i].resize(width, ' ');
        }

        if (!food.empty()) {
            grid[fp->first][fp->second] = 'F';
        }

         grid[0][0] = 'S';
    }

    inline bool isvalid (const Loc& pos, const char dir) { 
        if ((dir == 'U') && (pos.x == 0))
            return false; 
        
        if ((dir == 'D') && (pos.x == h-1))
            return false; 
        
        if ((dir == 'L') && (pos.y == 0))
            return false; 
        
        if ((dir == 'R') && (pos.y == w-1))
            return false; 
        
        return true; 
    }
    
    inline Loc nextLoc(Loc pos, const char direction)
    {
        if (direction == 'U') { 
            pos.x--;
        }
        else if (direction == 'D') { 
            pos.x++;
        }
        else if (direction == 'R') {
            pos.y++;
        }
        else if (direction == 'L') {
            pos.y--;
        }
        return pos; 
    }

    int move(string direction) {

        if (!isvalid(head, direction[0])) {
            return -1;
        }
        
        head = nextLoc(head, direction[0]); 
        q.push(direction[0]);

        // create the next food item on grid 
        if (grid[head.x][head.y] == 'F') {
            ++fp;
            if (fp != f.end()) {
                grid[fp->first][fp->second] = 'F';
            }
        }
        else {
            // mark old tail pos as empty 
            grid[tail.x][tail.y] = ' ';
			
			// fill the next tail location by getting direction.
            tail = nextLoc(tail, q.front());
            q.pop();
                    
			// if head of snake is on its own body, then quit. 
            if (grid[head.x][head.y] == 'S') {
                    return -1;
            }
        }
    
        grid[head.x][head.y] = 'S';
        return q.size();
    }
};

int main()
{ 
	return 0; 
} 
