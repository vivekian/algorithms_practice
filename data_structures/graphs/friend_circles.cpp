/* https://leetcode.com/problems/friend-circles/#/description */
/* use a DFS approach to iterate through all the friends and find the max number of circles */ 

#include <vector> 
#include <iostream> 
#include <queue> 

using namespace std; 

int findCircleNum(vector<vector<int>>& M)
{
    // final count of the total number of friend circles.
    int count=0; 

    // if a friend is already visited. 
    vector<bool> isVisited (M.size(), false);
    queue<int> tovisit; 

    for (int i=0; i<isVisited.size(); ++i) { 
        
        if (isVisited[i] == false) { 
            tovisit.push(i);
            ++count; 

            // once all friends are visited in a circle, then this while loop
            // will exit and we will search for another group in the for loop above.
            // this is really a connected components problem using BFS.
            while(!tovisit.empty()) { 
                // pop a friend from the front of the queue 
                int mate = tovisit.front();
                tovisit.pop();
                // mark the friend visited 
                isVisited[mate] = true;

                // for all the friends in the array 
                for (int j=0; j<M.size(); ++j) { 
                    // if a direct friend and not visited, push to queue to explore 
                    if ((M[mate][j] == 1) && (!isVisited[j]) && (mate != j)) {
                       tovisit.push(j);
                    }
                }
            }
        } 
    }

    return count; 
}    

int main()
{ 
    vector<vector<int>> friends = 
    {
        {1,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,0,0},
        {0,1,0,1,0},
        {0,0,0,0,1}
    };

    cout << findCircleNum(friends) << endl;
    return 0; 
}
