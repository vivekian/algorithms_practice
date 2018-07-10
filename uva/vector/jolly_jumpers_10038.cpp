#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

// can there be duplicate differences? 
bool isjolly(const vector<uint32_t>& nums) 
{
   vector<bool> present(nums.size()-1, false);

   for (int i=0 ;i<nums.size()-1; ++i) { 
        int diff = nums[i+1] - nums[i]; 

        if (diff < 0) 
            diff = -1 * diff;  

        if ((diff > nums.size()-1) && (diff < 1))
            return false; 

        present[diff-1] = true;  
   } 

   return (present.end() == 
           find_if(present.begin(), 
                   present.end(), [](const bool& b) {return (b == false);}));
}

int main()
{
    string s; 

    while (getline(cin, s)) { 

       if (s.empty()) 
           continue; 

       vector<uint32_t> nums; 
       stringstream ss(s); 
       string item; 
       int i=0; 
       
       while (getline(ss, item, ' ')) { 
            int num = stoi(item); 
            
            if (i==0) { 
                nums.reserve(num); 
            }
            else { 
                nums.push_back(num); 
            }

            ++i; 
       }
       
       cout << (isjolly(nums) ? "Jolly\n" : "Not jolly\n"); 
    }

    return 0;  
}
