#include <iostream> 
#include <string> 
#include <vector> 
#include <fstream> 

using namespace std; 

struct rect { 
    int left; 
    int top; 
    int w; 
    int h; 
}; 

// string was preprocessed to CSV using bash commands 
rect parse(string s) { 
    rect r; 

    auto pos = s.find(','); 
    r.left = stoi(s.substr(0, pos)); 
    auto pos2 = s.find(',', pos+1); 
    r.top = stoi(s.substr(pos+1, pos2 - pos)); 
    auto pos3 = s.find(',', pos2+1); 
    r.w = stoi(s.substr(pos2+1, pos3 - pos2)); 
    r.h = stoi(s.substr(pos3+1)); 
    return r;  
}

// mark the area which is getting filled 
void fill(vector<vector<int>> &v, rect& r) { 

    for (int i=r.top; i<r.top+r.h; ++i) { 
        for (int j=r.left; j<r.left + r.w; ++j) { 
                v[i][j]++; 
        }
    }

}

// compute area which has overlap 
long compute_overlap(vector<vector<int>>& v) { 
    long overlap = 0; 

    for (int i=0 ; i<1000; ++i) { 
        for (int j=0; j<1000; ++j) { 
            if (v[i][j] > 1) 
                ++overlap; 
        }
    }

    return overlap; 
}

// is a rectangle unique 
bool isunique(vector<vector<int>>& v, rect r) { 
     for (int i=r.top; i<r.top+r.h; ++i) { 
            for (int j=r.left; j<r.left+r.w; ++j) { 
                if (v[i][j] != 1) {
                    return false; 
                }
            }
     }

     return true; 
}

// iterate through all the rectangles and find the one 
// which is unique
int get_unique_id(vector<vector<int>>& v, vector<rect>& vr) 
{ 
    int idx = 1; 

    for (const rect r: vr) { 
        if (isunique(v, r)) { 
           return idx;  
        }   
        ++idx; 
    }

    return -1; 
}

int main()
{
    fstream myfile("output.csv", ios_base::in); 
    string s; 
    vector<vector<int>> v(1000); 
    vector<rect> vr; 

    for (int i=0; i<1000; ++i) { 
        v[i].resize(1000, 0); 
    }

    long square_inches = 0; 

    while(myfile >> s) { 
       auto r = parse(s); 
       vr.emplace_back(r); 
       fill(v, r); 
    }

    square_inches = compute_overlap(v); 
    cout << get_unique_id(v, vr) << endl; 
    cout << square_inches << endl; 
    return 0;  
}
