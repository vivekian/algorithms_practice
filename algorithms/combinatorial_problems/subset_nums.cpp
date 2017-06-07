#include <iostream> 
#include <vector> 

using namespace std; 

/* 				2,3,7 
				/	\
		(2), (3,7) 	(3,7) 
		/ \ 			| 
	(2,3),(7) (2),(7)  (3),(7) 	(7) 
	/	\		/ 	\	\ 	\	  \  \	
(2,3,7) (2,3) (2,7) (2) (3,7) (3) (7) ()
*/ 

void print(ostream& os, vector<int>& num) 
{ 
	for (const int& n: num) { 
		os << n << ","; 
	} 

	os <<endl; 
} 

void subsets_nums(vector<int> sofar, vector<int> rest, vector<vector<int>>& res) 
{
	if (rest.empty()) { 
		res.emplace_back(sofar); 
		return; 
	} 

	// there are always two choices when doing subsets 
	// 		- append the first element of rest to sofar and recurse.
	// 		- ignore the first element of rest and recurse with the rest.
	vector<int> next = sofar; 
	next.insert(next.end(), rest.begin(), rest.begin()+1); 
	subsets_nums(next, {rest.begin()+1, rest.end()}, res); 
	subsets_nums(sofar, {rest.begin()+1, rest.end()}, res); 
} 

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res; 
	subsets_nums({}, nums, res); 
	return res;         
}

struct test { 
	vector<int> in; 
	vector<vector<int>> out; 
}; 

namespace { 
	vector<test> testcases = { 
		{ {2,3,7}, {{2,3,7}, {2,3}, {2,7}, {2}, {3,7}, {3}, {7},{}}},
		{ {1}, {{1},{}} },
		{ {}, {{}} }
	}; 
}
 
int main() 
{
	for (auto& t: testcases) { 
		if (subsets(t.in) == t.out) { 
			cout << "test passed \n"; 
		} 
		else { 
			cout << "test failed \n"; 
		} 
	} 

	return 0;  
} 
