#include <unordered_map> 
#include <unordered_set> 
#include <queue> 
#include <iostream> 

using namespace std; 

int longestConsecutive(vector<int>& nums) {
    // for each number, record if immidiate numbers exist. 
    unordered_map<int, pair<bool, bool>> neighbors; 
    // during BFS, has number been visited. 
	unordered_set<int> visited; 
    // queue for BFS. 
	queue<int> q; 

    // for each number mark it as present, and also in its neigbors list. 
	for (auto& i: nums) { 
		neighbors[i] = {false, false}; 

        if (neighbors.find(i-1) != neighbors.end()) { 
            neighbors[i-1].second = true; 
            neighbors[i].first = true; 
        }

        if (neighbors.find(i+1) != neighbors.end()) { 
            neighbors[i+1].first = true; 
            neighbors[i].second = true;
        }
	}
    
    int max_count = 0; 

    for (const auto& n: neighbors) { 
        if (visited.find(n.first) == visited.end()) { 
            q.push(n.first); 
            int cnt = 0; 

            while (!q.empty()) { 
                auto item = q.front();
                q.pop(); 
                visited.insert(item); 
                ++cnt; 
    
                // if neighbor is not visited, push it to q. 
                if (neighbors[item].first && !visited.count(item-1)) { 
                    q.push(item-1); 
                }

                // if neigbhor is not visited, push it to q. 
                if (neighbors[item].second && !visited.count(item+1)) { 
                    q.push(item+1); 
                }
            }

            // update max_count. 
            if (cnt > max_count) { 
                max_count = cnt; 
            }
        }
    }

    return max_count;    
}

int main()
{
    vector<int> nums = {1,3,5,7,9,11,13,15,16,2,4,6,8,10}; 
    cout << longestConsecutive(nums) << endl;  
    return 0; 
} 
