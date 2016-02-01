// write the permutations of all binary numbers possible for a positive integer n. 
// e.g. n=2
// 00, 01, 10, 11 

#include <iostream> 
#include <string> 

void Permutate(std::string sofar, int k) 
{ 
    // we continue to permutate till all positions are filled. 
    if (sofar.length() == k) { 
        std::cout << sofar << std::endl;
        return;
    }

    // There are always 2 choices to be made for each position
    // either 0 or 1. 
    for (int i=0; i<2; ++i) { 
      std::string next = sofar + static_cast<char>(i+'0'); 
      Permutate(next, k); 
    }
}

int main() 
{ 
    Permutate("", 3); 
    return 0; 
}    
