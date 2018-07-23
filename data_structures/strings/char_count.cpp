
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

struct charcount { 
    int vowels = 0;
    int digits = 0; 
    int consonants = 0; 

    void print() 
    { 
        printf("vowels: %d, digits: %d, consonants: %d\n", 
                vowels, digits, consonants); 
    }
}; 

charcount count_chars(string T) 
{ 
    charcount res; 
    const string vowels = "AEIOUaeiou"; 

    for (const char c: T) { 
        if (isdigit(c)) { 
            res.digits++; 
        }
        else if (string::npos != vowels.find_first_of(c)) { 
            res.vowels++; 
        }
        else if (isalpha(c)) { 
            res.consonants++; 
        }
    }

    return res; 
}

int main()
{
    string str; 
    std::getline(std::cin, str); 
    charcount cc = count_chars(str);
    cc.print();  
    return 0;  
}
