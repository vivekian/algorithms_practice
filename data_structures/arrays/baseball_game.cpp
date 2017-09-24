#include <iostream> 
#include <string> 
#include <vector> 
#include <deque> 

using namespace std; 

int calpoints(vector<string>& ops) { 
  		int sum = 0;
        deque<int> q;

        for (const auto& s: ops) {
            if (s == "C") {
                sum -= q.back();
                q.pop_back();
            }
            else if(s == "D") {
                sum += (q.back() * 2);
                q.push_back(q.back() * 2);
            }
            else if (s == "+") {
                auto tmp = q.back() + q.at(q.size()-2);
                q.push_back(tmp); 
                sum += tmp; 
            }
            else {
                auto tmp = strtol(s.c_str(), nullptr, 10);
                sum += tmp; 
                q.push_back(tmp); 
            }
        }
        
        return sum; 
}


int main()
{
    return 0;  
}
