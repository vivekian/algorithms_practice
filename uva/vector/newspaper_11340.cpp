#include <algorithm> 
#include <numeric> 
#include <iostream> 
#include <string> 
#include <vector>
#include <unordered_map> 

using namespace std; 


float compute_money(const vector<string>& text, unordered_map<char, uint32_t>& charvalue) 
{
   long sum = 0; 

   for (const auto& t: text) { 
       sum += std::accumulate(t.begin(), 
                              t.end(), 
                              0, 
                              [&charvalue](long a, char c) { return a + charvalue[c]; }); 
   }

   return static_cast<float>(sum)/100; 
}

int main()
{
    int N; 
    cin >> N; 

    while (N) { 
        int K; 
        unordered_map<char, uint32_t> charvalue;  
        cin >> K;

        while (K) {
            char c; uint32_t v;  
            cin >> c >> v; 
            charvalue[c] = v; 
            --K; 
        }

        int M; 
        cin >> M;
        vector<string> para; 

        while (M) { 
            string s; 
            getline(cin, s);
        
            if (s.empty()) 
               continue;  
        
            para.push_back(move(s));  
            --M;
        }

        printf("%.2f$\n", compute_money(para, charvalue)); 
        --N;  
    }

    return 0;  
}
