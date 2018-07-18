#include <algorithm> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct problem {
    problem() {} 
    int ttime = 0; 
    bool solved = false; 
}; 

struct team { 
    team(int _id):id(_id)  { 
        probs.resize(7);
    }

    vector<problem> probs;   
    int total_time = 0; 
    int num_solved = 0; 
    int id = -1;
};

int main()
{
    vector<team> teams; 
    int id, h, m; 
    char p, s; 
    
    while (scanf("%d %c %d:%d %c", &id, &p, &h, &m, &s) != EOF) { 
            auto team_itr = find_if(teams.begin(), teams.end(), 
                    [&id](team &t) {return (t.id == id);}); 

            if (team_itr == teams.end()) 
            {
               team t(id); 
               teams.push_back(t); 
               team_itr = prev(teams.end()); 
            }

            if (s == 'Y') {
                team_itr->probs[p-'A'].solved = true; 
                team_itr->probs[p-'A'].ttime += (h*60) + m; 
                team_itr->total_time += team_itr->probs[p-'A'].ttime;  
                team_itr->num_solved++; 
            }
            else { 
                team_itr->probs[p-'A'].ttime += 20; 
            }
        }

    sort(teams.begin(), teams.end(), [](auto& a, auto& b) { 
            if (a.num_solved == 0) { 
                return false; 
            }
            
            if (a.num_solved == b.num_solved) { 
                return a.total_time < b.total_time; 
            }

            return a.num_solved > b.num_solved; 
        }); 

    printf("RANK TEAM PRO/SOLVED TIME\n"); 
    int rank=1; 

    for (size_t i=0; i<teams.size(); ++i) { 
        printf("%4d %4d %10d %4d\n", rank, 
                teams[i].id, teams[i].num_solved, teams[i].total_time); 
        
        if (i != teams.size()-1 && 
                teams[i].num_solved == teams[i+1].num_solved && 
                teams[i].total_time == teams[i+1].total_time) { 
            continue; 
        }
         
        ++rank; 
    }
 
    return 0;  
}
