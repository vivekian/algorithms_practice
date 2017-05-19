#include <iostream> 
#include <queue> 

using namespace std; 

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
       _size = size;  
    }
    
    double next(int val) {
		if (_size == 0) {
			return 0; 
		} 

		if (_num == _size) { 
			int item = _q.front(); 
			_q.pop(); 
			_sum -= item; 
		} 
		else { 
			++_num; 
		}
 
		_sum += val; 
		_q.push(val); 

		return static_cast<double>(_sum)/_num; 
    }

private: 
	int _size = 0; 
	int _num = 0;
	long _sum = 0;  
	queue<int> _q;  
};

struct test {
	int window;  
	vector<int> items; 
	vector<double> avg; 
}; 

namespace { 
	vector<test> tests = { 
		{ 2, {1, 2, 3, 4}, {1, 1.5, 2.5, 3.5} }
	}; 
} 
int main() 
{ 
	for (auto t: tests) { 
		MovingAverage avg(t.window); 
		int i=0;
 
		for (i=0; i<t.items.size(); ++i) { 
			auto res = avg.next(t.items[i]); 
			if (res != t.avg[i]) { 
				cerr << res << " " << t.avg[i] << endl; 
				cerr << "fail\n"; 
				break; 
			} 
		} 
		if (i == t.items.size()) { 
			cout << "pass\n";
		} 
	} 
	return 0; 	
} 

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
