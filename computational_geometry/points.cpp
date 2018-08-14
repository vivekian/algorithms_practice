#include <random> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct Point { 
    int x = 0, y = 0;
    Point() {} 

    Point(int _x, int _y): x(_x), y(_y) {} 

    bool operator < (Point other) const { 
        if (x == other.x) 
            return y < other.y; 
        return x < other.x; 
    }

    void print() const { 
        printf("x: %6d, y: %6d\n", x, y); 
    }
}; 

struct PointGenerator { 
    PointGenerator(int _num): num(_num) {}

    vector<Point> generate() { 
        int min = -10000; 
        int max =  10000; 
        vector<Point> res;  
        res.reserve(num); 
        random_device rd; 
        mt19937 rng(rd());
        uniform_int_distribution<int> uni(min,max);

        for (int i=0; i<num; ++i) { 
            res.push_back(Point(uni(rng), uni(rng)));
        }

        return res; 
    }

    int num; 
};

double euclidian_distance(const Point& p1, const Point& p2)  {
   int dx = p1.x - p2.x; 
   int dy = p1.y - p2.y; 

   return sqrt((dx*dx) + (dy * dy)); 
}

pair<Point, Point> find_closest_points(const vector<Point>& vp) { 
    int p1 = 0, p2 = 0;
    double min_dist = numeric_limits<double>::max();

    for (unsigned i=0; i<vp.size()-1; ++i) { 
        for (unsigned j=i+1; j<vp.size(); ++j) { 
            
            double curr_dist = euclidian_distance(vp[i], vp[j]); 
            if (curr_dist < min_dist) { 
                min_dist = curr_dist; 
                p1 = i; 
                p2 = j; 
            }

        }
    }

    return {vp[p1], vp[p2]};
}

int main()
{
    PointGenerator pg(1000); 
    auto vp = pg.generate();
    sort(vp.begin(), vp.end());
    
    for (const auto& p: vp) { 
        p.print(); 
    } 

    printf("closest points: \n"); 
    auto pp = find_closest_points(vp); 
    pp.first.print(); 
    pp.second.print(); 
    return 0;  
}
