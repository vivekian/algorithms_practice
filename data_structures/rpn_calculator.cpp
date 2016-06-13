// implement a reverse polish notation calculator for non-negative integers '0-9' and operators '+-*/%'
// RPN notation works this way: 
//      infix "5 + ((1 + 2) × 4) − 3"
//      RPN "512+4*3-"
// we can assume that there will be no more than 2 operands for every operator 

#include <algorithm> 
#include <cassert>
#include <cstring>
#include <iostream> 
#include <string> 
#include <stack> 
#include <vector> 

using namespace std; 

bool isOperator(const char k) 
{ 
    vector<char> ops = {'+','-','*','/','%'};
    
    if (ops.end() != find(ops.begin(), ops.end(), k)) 
        return true; 

    return false; 
}
    
bool isNumber(const char k) 
{ 
    int diff = k - '0'; 

    return (diff >= 0 && diff <= 9); 
}

int64_t operate(const char operand, int64_t op1, int64_t op2) 
{ 
    switch(operand) { 
        case '+': 
            return op1 + op2; 
        case '-': 
            return op1 - op2; 
        case '*': 
            return op1 * op2; 
        case '/': 
            return op1 / op2; 
        case '%': 
            return op1 % op2; 
    }

    return -1; 
} 

int32_t RPNCalculator(const char *input, int64_t &result)
{ 
    auto len = strlen(input); 
    assert(len);
    
    stack<int> st; 
   
    for (auto i=0; i<len; ++i) { 
         
        char c = input[i]; 

        if (isNumber(c)) { 
            st.push(c-'0'); 
            continue; 
        }

        if (isOperator(c)) { 

            if (st.empty() || st.size() == 1) { 
                cerr << "invalid input expression: no operands available" << endl; 
                return -1; 
            } 

            int64_t op2 = st.top(); st.pop(); 
            int64_t op1 = st.top(); st.pop(); 

            st.push(operate(c, op1, op2)); 
        }
        else { 
            cerr << "char neither operator nor operand" << endl;
            return -1; 
        } 
    }

    if (st.size() != 1) { 
        cerr << "invalid input expression" << endl; 
        return -1; 
    }

    result = st.top(); 
    st.pop(); 
    return 0; 
}

struct testcase { 
    const char *input; 
    int64_t result; 
    int32_t errcode; 
}; 

int main() 
{ 
    vector<testcase> testcases = { 
        {"54+", 9, 0}, 
        {"23-", -1, 0},
        {"512+4*+3-", 14, 0} 
    }; 

    for (const auto& test: testcases) { 
        
        int64_t res; 

        if (test.errcode != RPNCalculator(test.input, res)) { 
            cerr << "test failed" << endl; 
            return 1; 
        } 

        if (test.result != res) { 
            cerr << "test failed" << endl; 
            return 1; 
        } 
    }

    return 0; 
} 
