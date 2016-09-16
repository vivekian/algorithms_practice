#include <cstdio> 
#include <stdint.h> 

namespace { 
    const uint32_t MAX_SIZE = 1024; 
}

uint32_t solve_lcs_brute_force(const char* x, const char* y) 
{ 
    if (!x || !y) { 
        printf("input strings are empty");
        return 0; 
    } 

    const char *outerx = x;
    char subsequence[MAX_SIZE];  

    while (*outerx != '\0') { 
        const char *innerx = outerx; 
        while (*innerx) { 
            printf("%c\n", *innerx);
            ++innerx; 
        }
        printf("\n");
        outerx++; 
    }

    return 0; 
}

int main() 
{ 
    solve_lcs_brute_force("ABCBDAB", "BDCABA"); 
    return 0; 
}
