#include <unordered_map> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {

    unordered_map<string, int> listindex; 
    vector<pair<string, int>> avg; 

    for (int i=0; i<list1.size(); ++i) { 
        listindex[list1[i]] = i; 
    }

    for (int i=0; i<list2.size(); ++i) { 
        auto str = list2[i]; 
        if (listindex.count(str)) { 
            avg.push_back({str, i + listindex[str]});
        }
    }

    auto comp = [](const auto& a, const auto &b) {return a.second < b.second; };
    sort(avg.begin(), avg.end(), comp); 
    
    vector<string> res; 

    for (int i=0; i<avg.size(); ++i) { 
        res.emplace_back(avg[i].first); 

        if ((i != avg.size()-1) && avg[i+1].second != avg[i].second) { 
            break; 
        }
    }

    return res;  
}

int main()
{
    return 0;  
}
