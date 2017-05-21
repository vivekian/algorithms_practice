// solution to problem 593 (valid square) 

#include <cmath> 
#include <vector> 
#include <iostream> 

using namespace std; 

bool areSame(double a, double b) 
{ 
    return fabs(a-b) < 0.1; 
} 

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

    vector<int> bl, br, tl, tr; 
    vector<vector<int>> res = {p1, p2, p3, p4}; 

    vector<double> distances; 

    /* compute distances between all points */ 
    for (int i=0; i<4; ++i) { 
        for (int j=i+1; j<4; ++j) { 
            distances.push_back(sqrt(pow(res[i][0]-res[j][0],2) + 
                                     pow(res[i][1]-res[j][1],2))); 
        }
    } 

    sort(distances.begin(), distances.end()); 

    /* make sure first 4 distances are the same */ 
    for (int i=0; i<3; ++i) { 
        if (!areSame(distances[i], distances[i+1])) { 
            return false; 
        } 
    } 

    double hypo = sqrt(2) * distances[0]; 

    /* make sure that the last 2 distances is equal to the hypotonuse*/ 
    if (!areSame(hypo, distances[4]) || !areSame(hypo, distances[5])) { 
        return false; 
    } 

    return true; 
}

int main()
{ 	
	vector<int> p1 = {0,0}; 
    vector<int> p2 = {1,1}; 
 	vector<int> p3 = {1,0}; 
	vector<int> p4 = {0,1}; 
    
    cout << validSquare(p1,p2,p3,p4) << endl; 
}
