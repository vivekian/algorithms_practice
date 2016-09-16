#include <iostream> 
#include <utility> 
#include <vector> 

using namespace std; 

// euclidean algorithm. 
//      if b == 0, then just return a. 
//      else 
//          take the modulus of a/b, and recursively call gcd again with (b, remainder) 
//      
//      this is based on the observation that the common divisors of a and b are precisely 
//      the same as the common divisors of b and r. 

uint32_t gcd(uint32_t a, uint32_t b) 
{ 
    if (b == 0) 
        return a; 

    return gcd(b, (a % b)); 
}

struct testcase { 
    pair<uint32_t, uint32_t> input; 
    uint32_t res; 
}; 

int main() 
{ 
    const vector<testcase> testcases = { 
        {{54, 24}, 6}, 
        {{206, 40}, 2},
        {{2, 0}, 2}, 
        {{0, 0}, 0}, 
        {{180, 48}, 12}
    }; 

    for (auto& test: testcases) { 
        if (test.res != gcd(test.input.first, test.input.second)) { 
            cout << "test failed\n" << endl; 
        }
    }

    return 0; 
}
