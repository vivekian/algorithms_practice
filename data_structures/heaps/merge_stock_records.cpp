#include <iostream> 
#include <queue> 
#include <string> 
#include <vector> 

using std::string; 
using std::vector; 
using std::priority_queue; 
using std::cout;
using std::endl; 

struct stock_record { 
    uint32_t timestamp; 
    string name; 
    double stock_price; 
    uint32_t vector_index; 

    void print() 
    { 
        cout << timestamp << " " << name << " " << stock_price << " " << endl; 
    } 
}; 

using stock_records = vector<stock_record>; 

// compartor function to prioritize items in priority_queue
namespace { 
    auto comp = [] (stock_record& a, stock_record& b) 
    { return a.timestamp > b.timestamp; };  
}

// This is a k-way merge of multiple lists of stock price entries based on their timestamps. 
// Each list on its own is sorted based on the timestamp. We maintain a priority queue 
// and enter the first record of each list. Next, we extract the minimal timestamp item from the 
// pirority queue and insert it into the single merged_recs list. Since we know which list 
// this item belongs to, we extract the next item from that list as well. 
stock_records MergeRecords(vector<stock_records>& recs) 
{ 
    priority_queue<stock_record, stock_records, decltype(comp) > pq(comp);  
    stock_records merged_recs;
    
    // these indexes maintain how far we have progresses through each of the vectors. 
    vector<uint32_t> indexes (recs.size()); 

    // enter the first element of every vector in the priority queue 
    for (auto i=0; i < recs.size(); ++i) { 
        recs[i][0].vector_index = i; 
        pq.emplace(recs[i][0]);  
        indexes[i]++;  
    }    

    while (!pq.empty()) {
        // extract the first item 
        auto min_item = pq.top();  
        merged_recs.emplace_back(min_item); 
        pq.pop();

        auto vec_idx = min_item.vector_index; 

        // goto the list and extract the next item, updating indexes 
        if (indexes[vec_idx] < recs[vec_idx].size())
        { 
            pq.emplace(recs[vec_idx][indexes[vec_idx]]); 
            indexes[vec_idx]++; 
        }
           
    }

    return merged_recs; 
} 

vector<stock_records> MakeRecords() 
{ 
    return {{ 
                   {1000, "NVDA", 12.23}, 
                   {1050, "AAPL", 23.45}, 
                   {1200, "TSLA", 22.99}
           }, 
           { 
                   {1010, "CSCO", 67.89}, 
                   {1230, "AAPL", 44.56}, 
                   {1530, "GOOG", 566.23}, 
           }, 
           { 
                   {1005, "AMD", 6.45}, 
                   {1007, "WFC", 47.23}
           } 
           };
}

int main() 
{
    vector<stock_records> recs = MakeRecords();  
    stock_records merged_recs = MergeRecords(recs); 

    for (auto& rec: merged_recs) { 
        rec.print(); 
    } 

    return 0; 
}     
