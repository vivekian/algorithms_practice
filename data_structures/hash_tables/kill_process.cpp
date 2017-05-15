#include <queue> 
#include <unordered_map>
#include <vector> 
#include <iostream> 

using namespace std; 

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) 
{
    vector<int> res;
    unordered_map<int, vector<int>> pcmap;

    for (int i=0; i<ppid.size(); ++i) { 
        pcmap[ppid[i]].push_back(pid[i]);
    }

    queue<int> q; 
    q.push(kill); 

    while (!q.empty()) { 
        int item = q.front(); 
        q.pop(); 
        res.push_back(item); 
        auto children = pcmap.find(item); 

        if (children != pcmap.end()) { 
            for (const auto& i: children->second) { 
                q.push(i); 
            }
        }
    }
    
    return res; 
}

struct test { 
    vector<int> pid; 
    vector<int> ppid; 
    int kill;
    vector<int> res; 
};

namespace { 
    vector <test> tests = { 
        { {1,3,10,5}, {3,0,5,3}, 5, {5,10}},
        { {1,3,10,5}, {3,0,5,3}, 10, {10}},
        { {1,3,10,5}, {3,0,5,3}, 0, {0,3,1,5,10}},
        { {1,3,10,5}, {3,0,5,3}, 1, {1}}
    };
} 

int main()
{ 
    for (auto& t: tests) { 
        if (killProcess(t.pid, t.ppid, t.kill) == t.res) { 
            cout << "pass\n"; 
        }
        else { 
            cerr << "fail\n";
        }
    }

    return 0; 
} 
