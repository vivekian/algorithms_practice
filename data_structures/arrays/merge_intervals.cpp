#include <iostream> 
#include <vector> 

using namespace std; 

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

void print(ostream& out, vector<Interval>& in) 
{ 
	for (const auto& a: in) { 
		out << a.start << " " << a. end << endl; 
	} 
} 

vector<Interval> merge(vector<Interval>& intervals) {
	
	if (!intervals.size() || intervals.size() == 1) { 
		return intervals; 
	} 	

	vector<Interval> res; 

	sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) 
		 { return a.start < b.start; }); 

	int curr_start = intervals[0].start; 
	int curr_end = intervals[0].end; 

	for (int i=1; i < intervals.size(); ++i) { 

        if (intervals[i].start <= curr_end) { 
			if (intervals[i].end > curr_end) { 
				curr_end = intervals[i].end; 
			}
		} 
		else { 
			res.push_back(Interval(curr_start, curr_end));
			curr_start = intervals[i].start; 
			curr_end = intervals[i].end; 
		} 
	} 

    res.push_back(Interval(curr_start, curr_end)); 
	return res; 
}

int main() 
{
	vector<Interval> vec = {{2,8}, {1,4}, {3,5}, {10,13}, {11,15}};
	auto res = merge(vec); 
	print(cout, res); 
	vec = {{1,3}, {4,5}};
	res = merge(vec); 
	print(cout, res); 


	return 0;  
}
