/* https://leetcode.com/problems/friend-circles/#/description */
/* use a DFS approach to iterate through all the friends and find the max number of circles */ 

#include <vector> 
#include <iostream> 
#include <queue> 

using namespace std; 

int findCircleNum(vector<vector<int>>& M)
{
    int count=0; 
    vector<bool> isVisited (M.size(), false);
    queue<int> tovisit; 

    for (int i=0; i<isVisited.size(); ++i) { 
        
        if (isVisited[i] == false) { 
            tovisit.push(i);
            ++count; 

            while(!tovisit.empty()) { 
                int mate = tovisit.front();
                tovisit.pop();
                isVisited[mate] = true;

                for (int j=0; j<M.size(); ++j) { 
                    
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
