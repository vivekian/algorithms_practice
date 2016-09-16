// This is essentially a subset problem and every subset problem requires 
// two choices to be made. Here the choices are to add an opening brace 
// and the other choice is to add the closing brace. In addition two more
// parameters have to be added which maintain the count of paranthesis. 

#include <cstdio> 
#include <string> 

void SubsetParanthesis(std::string Paranthesis, uint32_t k, uint32_t open, uint32_t close) 
{
    if (close == k) 
    { 
       printf("%s\n", Paranthesis.c_str());
       return; 
    } 

    if (open > close) { 
        SubsetParanthesis(Paranthesis+')', k, open, close+1);
    } 
    if (open < k) { 
        SubsetParanthesis(Paranthesis+'(', k, open+1, close); 
    } 
}

int main() 
{ 
    SubsetParanthesis("", 4, 0, 0); 
}
