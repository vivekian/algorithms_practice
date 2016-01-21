#include <algorithm> 
#include <stdint.h>
#include <cstdio> 

// this is a solution to the assembly scheduling problem described in 
// chapter 15.1 of CRCT (Introduction to Algos 2nd Edition). 
// solve from left to right by finding the shortest time it takes to get 
// the next station. Solutions to smaller subproblems feed to the bigger
// solution as we move to the right. 

namespace { 
    const uint32_t MAX_STATIONS = 6;
} 

uint32_t fastest_way() 
{ 
    uint32_t assembly_time[MAX_STATIONS][2] = { 
        {7,8}, 
        {9,5},
        {3,6},
        {4,4},
        {8,5},
        {4,7}};

    uint32_t transition_time[MAX_STATIONS][2] = {
        {0,0},
        {2,2},
        {3,1},
        {1,2},
        {3,2},
        {4,1}};

    uint32_t entry_time1 = 2; 
    uint32_t entry_time2 = 4; 
    uint32_t exit_time1 = 3;
    uint32_t exit_time2 = 2; 

    uint32_t fastest1[MAX_STATIONS], fastest2[MAX_STATIONS];
   
    fastest1[0] = entry_time1 + assembly_time[0][0];
    fastest2[0] = entry_time2 + assembly_time[0][1];

    for (uint32_t j = 1; j < MAX_STATIONS; ++j) { 
        fastest1[j] = std::min(fastest1[j-1] + assembly_time[j][0], 
                         fastest2[j-1] + assembly_time[j][0] + transition_time[j][1]);

        fastest2[j] = std::min(fastest2[j-1] + assembly_time[j][1], 
                         fastest1[j-1] + assembly_time[j][1] + transition_time[j][0]);
    }

    printf(" f1  f2\n");
    
    for (uint32_t i = 0; i < MAX_STATIONS; ++i) { 
        printf("%3u %3u\n", fastest1[i], fastest2[i]);
    }

    return std::min(fastest1[MAX_STATIONS-1] + exit_time1, 
                    fastest2[MAX_STATIONS-1] + exit_time2);
}

int main()
{ 
    uint32_t shortest_time = fastest_way();
    printf("Shortest time: %u\n", shortest_time);
    return 0; 
} 
