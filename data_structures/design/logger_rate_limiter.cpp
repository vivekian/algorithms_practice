#include <iostream> 
#include <string> 
#include <unordered_map>

using namespace std;

class Logger {
private: 
	unordered_map<string, int> keyvalue; 

public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
		if (keyvalue.find(message) == keyvalue.end()) { 
			keyvalue[message] = timestamp;         
			return true; 
		} 
		
		if (timestamp - keyvalue[message] >= 10) { 
			keyvalue[message] = timestamp; 
			return true; 
		} 

		return false; 
    }
};

int main() 
{ 
	Logger logger; 
	cout << logger.shouldPrintMessage(1, "foo") << endl; 
	cout << logger.shouldPrintMessage(2, "bar") << endl; 
	cout << logger.shouldPrintMessage(3, "foo") << endl; 
	cout << logger.shouldPrintMessage(8, "bar") << endl; 
	cout << logger.shouldPrintMessage(10, "foo") << endl; 
	cout << logger.shouldPrintMessage(11, "foo") << endl; 

	return 0; 
} 

