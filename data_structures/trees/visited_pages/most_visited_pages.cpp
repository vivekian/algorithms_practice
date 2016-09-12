// this solves the problem 15.8 of EPI (Elements of Programming Interviews) 

#include <fstream> 
#include <functional> 
#include <iostream> 
#include <map>
#include <string> 
#include <vector> 

using namespace std; 

struct file_entry { 
    int64_t timestamp; 
    string name; 
};

typedef pair<string, int> visit_count; 

// the solution involves reading the log file and building a frequency count map
// of each unique web page name. next we can sort these entries in a vector using 
// the frequency count and retreive the k highest entries. 
//
// time complexity: O(n) to read all the entries and build frequency map 
//                  O(m) to copy the entries to a vector where m is the number of distinct pages
//                  O(m lg m) to sort the entries. 

namespace {
    auto visit_count_greater = [] (const visit_count& a, const visit_count& b) { 
        return a.second > b.second; 
    };

    map<string, int> s_visitcount_map; 
    vector<pair<string, int>> s_sorted_visitcount; 
} 

void add_visit_entry(const string& page_name)
{ 
    // update the page frequency table
    auto visit_entry = s_visitcount_map.find(page_name); 
    if (visit_entry == s_visitcount_map.end()) { 
        s_visitcount_map[page_name] = 1; 
    } 
    else { 
        visit_entry->second++;  
    } 
} 

void sort_by_highest() 
{
    s_sorted_visitcount.resize(s_visitcount_map.size()); 

    transform(s_visitcount_map.begin(), 
              s_visitcount_map.end(), 
              s_sorted_visitcount.begin(),
              [](visit_count a){ return a; });

    sort(s_sorted_visitcount.begin(), s_sorted_visitcount.end(), visit_count_greater); 
} 

void read_log_entries(const string& filename) 
{ 
    ifstream infile(filename); 
    file_entry entry; 
    
    while (infile >> entry.timestamp >> entry.name) { 
        add_visit_entry(entry.name); 
    } 
} 

void write_k_sorted_entries(ostream& os, const int k) 
{ 
    for (int i = 0; i < k; ++i) { 
        os << s_sorted_visitcount[i].first << " " << s_sorted_visitcount[i].second << endl; 
    } 
} 

int main() 
{
    int k = 4; 
    read_log_entries(string("pages.log"));
    sort_by_highest(); 
    write_k_sorted_entries(cout, k); 
    return 0; 
} 

