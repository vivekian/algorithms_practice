// solution to problem 7.5 of EPI (Elements of Programming Interviews) 
//
// algorithm: 
//  - pick the first digit from the phone no
//  - map it to all the letters corresponding to it. 
//  - iterate all the letters belonging to that digit: 
//          * for each letter call generate_sequence recursively
//          * append the letter to the string, and take substring for the second 
//            string by removing the selected letter.

#include <iostream> 
#include <map> 
#include <string>

using std::string; 
using std::cout; 
using std::endl; 
using std::map; 

namespace { 
    map<char, string> s_digitmap = { 
        {'2', {"abc"}},
        {'3', {"def"}}, 
        {'4', {"ghi"}}, 
        {'5', {"jkl"}},
        {'6', {"mno"}},
        {'7', {"pqrs"}},
        {'8', {"tuv"}},
        {'9', {"wxyz"}}
    }; 
} 

void generate_sequence(string sofar, string rest) 
{ 
    if (rest.empty()) { 
        cout << sofar << endl; 
    } 
    else { 
        auto letters = s_digitmap[rest[0]]; 

        for (int i=0; i<letters.size(); ++i) { 
            generate_sequence(sofar + letters[i], rest.substr(1)); 
        }
    } 
} 

void solve_mnemonics(string phone_no) 
{
    generate_sequence("", phone_no); 
} 

int main()
{
    solve_mnemonics(string("462"));  
    return 0; 
} 
