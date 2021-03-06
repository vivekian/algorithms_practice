#include <iostream> 
#include <algorithm> 

using namespace std; 

struct rectangle { 
    int leftx; 
    int rightx; 
    int bottomy; 
    int topy;

    rectangle() {}  

    rectangle(int lx, int rx, int by, int ty)  
    { 
        leftx = lx; 
        rightx = rx; 
        bottomy = by; 
        topy = ty; 
    } 

    bool intersect(const rectangle& other) 
    { 
        bool xintersect = false, yintersect = false; 

        if (((other.leftx >= leftx) && (other.leftx <= rightx)) || 
            ((other.rightx >= leftx) && (other.rightx <= rightx))) { 
                    xintersect = true; 
        } 

        if (((other.bottomy >= bottomy) && (other.bottomy <= topy)) || 
            ((other.topy >= bottomy) && (other.topy <= topy))) { 
                    yintersect = true; 
        } 

        return xintersect && yintersect; 
    } 

    void write(ostream& os) 
    {
        os << leftx << "," << rightx << "," << bottomy << "," << topy << endl; 
    } 
     
};

rectangle super_rectangle(const rectangle& a, const rectangle& b) 
{ 
    rectangle res; 
    
    res.leftx = std::min(a.leftx, b.leftx); 
    res.rightx = std::max(a.rightx, b.rightx); 
    res.bottomy = std::min(a.bottomy, b.bottomy); 
    res.topy = std::max(a.topy, b.topy); 

    return res; 
} 

int main() 
{
    rectangle r1(10, 20, 0, 100); 
    rectangle r2(15, 25, 50, 150); 
    rectangle r3(21, 25, 50, 150); 

    cout << r1.intersect(r2) << endl; 
    cout << r1.intersect(r3) << endl; 
    cout << r2.intersect(r3) << endl; 
    cout << r3.intersect(r2) << endl; 
    cout << r3.intersect(r3) << endl; 

    rectangle r4 = super_rectangle(r1, r2); 
    r4.write(cout); 

    return 0; 
}
