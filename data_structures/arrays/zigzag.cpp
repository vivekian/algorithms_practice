// solution to problem 281 of Leetcode (zigzag iterator) 
// https://leetcode.com/problems/zigzag-iterator/#/description

#include <vector> 
#include <iostream> 

using namespace std; 

class ZigzagIterator {
private: 
	vector<int> _v1; 
	vector<int> _v2; 
	bool _isv1; 
	int i; 
	int j; 

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
		_v1 = v1; 
		_v2 = v2;        	 
		_isv1 = !v1.empty();
		i = 0; j = 0; 
    }

    int next() {
		int ret = 0; 

		if (i >= _v1.size()) { 
			ret = _v2[j++];
		} 
		else if (j >= _v2.size()) { 
			ret = _v1[i++]; 
		}  
		else if (_isv1) { 
			ret = _v1[i++]; 
			_isv1 = false; 
		}  
		else if (!_isv1) { 
			ret = _v2[j++]; 
			_isv1 = true;
		}
	
		return ret; 	
    }

    bool hasNext() {
     	return (i < _v1.size() || j < _v2.size()); 
    }
};

int main() 
{ 
	vector<int> v1 = {}; 
	vector<int> v2 = {}; 

	ZigzagIterator i (v1, v2);
    while (i.hasNext()) cout << i.next();
	return 0; 
}

