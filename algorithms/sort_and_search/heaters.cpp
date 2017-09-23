#include <limits> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

int findRadius(vector<int>& houses, vector<int>& heaters) {
	sort(houses.begin(), houses.end()); 
	sort(heaters.begin(), heaters.end()); 
	
	auto hlen = houses.size();
	auto heaterlen = heaters.size(); 
	int maxradius = numeric_limits<int>::min();

	for (int i=0; i<hlen; ++i) {
			auto itr = lower_bound(heaters.begin(), heaters.end(), houses[i]);
		
			// if the house is beyond a heater, choose the last available heater. 
			int idx =  (itr == heaters.end()) ? heaterlen-1 : itr - heaters.begin(); 
			int radius = abs(heaters[idx] - houses[i]);

			// compare with the heater just before this heater 
			if (idx != 0) {
				radius = min(radius, abs(houses[i] - heaters[idx-1]));
			}

			// pick the max radius amongst all the houses 
			maxradius = max(radius, maxradius);
	}

	return maxradius;   
}       

int main()
{
	return 0;  
}
