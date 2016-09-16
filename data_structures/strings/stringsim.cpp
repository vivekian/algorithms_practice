#include <string> 
#include <vector> 
#include <iostream> 
#include <ctype.h> 

using namespace std; 

int GetSimilarStringLength(const char* InputStr, const char* Suffix) 
{ 
	int count = 0; 

	while(*Suffix != '\0') { 
		if(*Suffix == *InputStr) { 
			count++;  
		}
		else { 
			break; 
		} 
		++Suffix; 
		++InputStr; 
	}
 
	return count; 
} 

int SumStringSimilarity(char* InputString) 
{ 
	char* suffix = InputString; 
	int sum = 0;
	int lengthStr = 0;  

	while(*suffix != '\0') {
		if (0 == islower(*suffix)) { 
			sum = -1; 
			break;
		} 
 
		sum += GetSimilarStringLength(InputString, suffix); 
		++suffix; 
		++lengthStr; 
	} 

	if(lengthStr > 100000) { 
		sum = -1; 
	} 

	return sum; 
}

int GetNumTestCases() 
{ 
	int num; 
 	cin >> num;
	return num;   
}

void GetTestCases(vector<string>& InputTestCases, const int NumTestCases) 
{
	string testCase; 

	for (int idx = 0; idx < NumTestCases; ++idx) {
		cin >> testCase; 
		InputTestCases.push_back(testCase); 
	} 
} 

int main() 
{
	vector<string> vTestCases; 
	int numTestCases = GetNumTestCases(); 
	
	if(numTestCases < 1 || numTestCases > 10) 
	{ 
		cerr << "Number of test cases is outside range" << endl; 
		return 1; 
	}
	
	GetTestCases(vTestCases, numTestCases);

	vector<string>::iterator testCase; 
	
	for(testCase = vTestCases.begin(); testCase != vTestCases.end(); ++testCase) 
	{ 
		int sum = SumStringSimilarity(const_cast<char*>(testCase->c_str())); 
		
		if(sum == -1) { 
			cerr << "input string is not valid" << endl;
			return 1;  
		} 
	
		cout << sum << endl; 
	}  
	
	return 0; 
} 
