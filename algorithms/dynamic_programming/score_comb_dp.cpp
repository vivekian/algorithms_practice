// this is a dynamic programming solution to problem 17.1 of the elements of programming
// interview book. This is very similar to the coin change problem where we need
// to find out the different ways a set of coins can add upto a certain amount. 
//
// the key finding here is that this is a subset problem where we have to enlist all subsets 
// but we need to keep going till we sum upto a certain amount. 

#include <cstdio> 
#include <stdint.h> 
#include <cstring> 

namespace { 
    uint32_t a[] = {0, 2, 3, 7}; 
    int** score_records;

    void AllocateMemory(const int score) 
    { 
        score_records = new int*[score]; 

        for (int i=0; i<=score; ++i) { 
            score_records[i] = new int[4];
        }

        for (int i=0; i<score; ++i) { 
            for (int j=0; j<4; ++j) { 
                score_records[i][j] = 0; 
            }
        }
    }

    void ClearMemory(const int score) 
    { 
        for (int i=0;  i<score; ++i) { 
            delete[] score_records[i]; 
        }

        delete[] score_records; 
    }


}

int score_combinations(const int score, const uint32_t n) 
{ 
    if (score == 0) 
        return 1; 

    if (score < 0 || n == 0) 
        return 0;

    if (score_records[score-1][n]) 
       return score_records[score-1][n]; 

    int result = score_combinations(score, n-1) + 
                 score_combinations(score-a[n], n); 

    score_records[score-1][n] = result; 
    return result; 
} 

int ListScoreCombinations(const int score) 
{
    AllocateMemory(score); 
    int ret = score_combinations(score, 3); 
    ClearMemory(score);
    return ret;  
}

int main() 
{ 
    printf("%u\n", ListScoreCombinations(4000));
    printf("%u\n", ListScoreCombinations(6));
}
