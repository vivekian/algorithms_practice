#include <cstring> 
#include <iostream> 
#include <utility> 

using namespace std; 

void reverse_word(char* word, char seperator) 
{ 
    if (!word || !(*word)) 
        return; 

    char* s = word, *t = word; 

    // iterate to the end of the word 
    while ((*s != seperator) && (*s != '\0')) 
        s++; 

    --s; 
     
    while (s > t) {  
        char tmp = *t; 
        *t = *s; *s = tmp; 
        ++t; --s; 
    } 
} 

void reverse_sentence(char* sentence) 
{ 
    reverse_word(sentence, '\0'); 
    char* t = sentence;
    
    reverse_word(t, ' ');  

    while (*t != '\0') { 
        if (!strncmp(t, " ", 1)) { 
            ++t; 
            reverse_word(t, ' '); 
        }
        ++t; 
    }  
}

int main() 
{ 
    char sentence[] = "the quick brown fox ran over the fence"; 
    reverse_sentence(sentence); 
    cout << sentence << endl; 
    reverse_sentence(sentence); 
    cout << sentence << endl; 
    return 0; 
} 
