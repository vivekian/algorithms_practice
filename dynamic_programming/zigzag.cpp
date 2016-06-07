// Problem Statement: https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493

#include <cstdio>
#include <stdint.h> 

bool getSign (const int a, const int b) 
{ 
    return (a - b) > 0 ? true: false; 
}

int longestZigZag (int input[], int seqlen) 
{ 
    // the cases where the input array has 0, 1 or 2 elements. 
    if (seqlen == 0 || seqlen == 1 || seqlen == 2) 
    { 
        return seqlen; 
    } 

    uint32_t subseqlen = 1;
    bool curSign = !getSign(input[0], input[1]); 
    uint32_t lastIdx = 0; 

    for (int i=0; i<seqlen-1; ++i) { 
        if ((input[lastIdx] != input[i+1]) && 
            (curSign != getSign(input[lastIdx], input[i+1]))) { 
                subseqlen++; 
                curSign = !curSign; 
                lastIdx = i+1;
       }
     }

     return subseqlen;
}

int main() 
{ 
    int testcases[6][100] = { 
        { 1, 7, 4, 9, 2, 5 }, 
        { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }, 
        { 44 }, 
        { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 
        { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }, 
        { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
          600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
          67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
          477, 245, 413, 109, 659, 401, 483, 308, 609, 120,
          249, 22, 176, 279, 23, 22, 617, 462, 459, 244 }
    };

    int lentests[] = {6, 10, 1, 9, 19, 50}; 

    for (int test=0; test<6; ++test) 
    { 
        printf("subseq length = %d\n", longestZigZag(testcases[test], lentests[test]));
    }

    return 0; 
}

