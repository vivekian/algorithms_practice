// simple regular expressions
//
// * - match 0 or more of the preceeding character. 
// . - match any alphanumeric character. 
// e.g. al.*a will match alpha, alsa, alta. 
//
#include <iostream> 
#include <cctype> 
#include <vector> 

using namespace std; 

// match 0 or more of character pointed by p 
int match_star_chars(const char* text, int t, char p) 
{
    int s = t; 

    while(text[t] && (text[t] == p)) { 
       ++t;
    } 

    return (t - s); 
}  

bool grep_sre_helper(const char* text, const char* regex, int t_index, int r_index) 
{
    // check for $ char first before hitting other cases 
    if (regex[r_index] == '$') { 
        return (!text[t_index] && !regex[r_index+1]); 
    } 

    // if text is over, but regex is not completed. 
    if (!text[t_index]) { 
        return (!regex[r_index]); 
    } 

    // if text exists, but regex is over
    if (text[t_index] && !regex[r_index]) { 
        return true; 
    } 

    int inc = 1; 

    // if metacharacter . occurs, then we match any character in the text 
    if (regex[r_index]== '.') { 
        ++r_index; 
    }
    else if (regex[r_index]== '*') { 
        
        // * can't begin at the start of the regex since there is no preceeding char 
        if (r_index == 0) { 
            return false; 
        } 
       
        inc = match_star_chars(text, t_index, text[t_index-1]); 
        ++r_index; 
    } 
    else if (isalnum(regex[r_index])) {
       
        if (regex[r_index] != text[t_index]) { 
            return false; 
        } 

        ++r_index; 
    }
    // invalid char  
    else { 
        return false; 
    } 

    t_index += inc; 
    return grep_sre_helper(text, regex, t_index, r_index); 
} 

bool grep_sre(const char* text, const char* regex) 
{
    if (regex[0] == '^') {
        return grep_sre_helper(text, regex, 0, 1); 
    } 

    // go through each char in the text to match the substring
    for (int i=0; i<strlen(text); ++i) { 
       if (grep_sre_helper(text, regex, i, 0)) { 
          return true; 
       } 
    } 

    return false; 
} 

void run_test_cases() 
{
   struct test { 
      const char* text; 
      const char* regex; 
      bool result; 
   }; 

    vector<test>  testlist = {
        { "apple", "app", true }, 
        { "apple", "pp" , true },
        { "apple", "ppo", false},
        { "apple", "pp.", true },  
        { "apple", "p*.", true },  
        { "apple", "*apple", false}, 
        { "apple", "a*p.le", true},  
        { "apple", "a.*le",  true}, 
        { "apppple", "a.*le", true}, 
        { "appbpple", "a.*le", false},  
        { "apple", "^apple", true},
        { "apple", "^pple", false},
        { "apple", "^apple$", true},
        { "apple", "pple$", true}, 
        { "apple", "p*l.$", true}
    }; 

    for (const auto& test: testlist) { 
       cout << "text: " << test.text << " regex: " << test.regex << " "; 

       if (grep_sre(test.text, test.regex) != test.result) { 
           cout << "test failed" << endl; 
       } 
       else { 
          cout << "\n"; 
       }  
    }
}   

int main() 
{ 
    run_test_cases();
    return 0;
}  
