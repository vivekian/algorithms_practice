// this is a recursive solution to problem 17.1 of the elements of programming
// interview book. This is very similar to the coin change problem where we need
// to find out the different ways a set of coins can add upto a certain amount. 
//
// the key finding here is that this is a subset problem where we have to enlist all subsets 
// but we need to keep going till we sum upto a certain amount. 

#include <cstdio> 

namespace { 
    int a[] = {0, 2, 3, 7}; 
}

int score_combinations(const int score, const int n) 
{ 
    if (score == 0) 
        return 1; 

    if (score < 0 || n == 0) 
        return 0; 

    return score_combinations(score, n-1) + 
           score_combinations(score-a[n], n); 
} 

int PossibleScoreCombinations(const int score) 
{ 
    return score_combinations(score, 3); 
}

int main() 
{ 
    printf("%u\n", PossibleScoreCombinations(21));
}
