#include <algorithm> 
#include <vector> 
#include <iostream> 

struct compare 
{ 
	bool operator() (const char* a, const char* b) 
	{ 
		return (strcmp(a, b) < 0) ? true : false; 
	} 
} mycompare; 

int main() 
{ 
	const char* lines[] = 
	{ 
		"independence day", 
		"forest gump", 
		"the curious case of benjamin button", 
		"good will hunting",
		"contact", 
		"zorro", 
		"a walk to remember" 
	};

	int numLines = sizeof(lines) / sizeof(const char*); 
	std::vector<const char*> vLines(lines, lines + numLines); 
	std::sort(vLines.begin(), vLines.end(), mycompare); 

	for(const char* x: vLines) 
		std::cout << x << std::endl; 	

	return 0; 
} 
