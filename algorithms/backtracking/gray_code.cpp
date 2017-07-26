/* 
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that. */ 

#include <vector> 
#include <iostream> 

using namespace std; 

void write(vector<int>& v) {
    for (const auto& i: v) {
        cout << i << " "; 
    }

    cout << endl; 
}

void generate(int num, int n, vector<int>& v)
{
    if (n == 0) 
        return; 

    for (int i=0; i<n; ++i) { 
       int next = num | (1 << i);
       generate(next, i, v); 
       v.push_back(next); 
    }
}

vector<int> gray_code(int n) 
{
   vector<int> res;  
   res.emplace_back(0); 
   generate(0, n, res); 
   return res; 
}

int main() 
{
   auto res = gray_code(3); 
   write(res);  
}
