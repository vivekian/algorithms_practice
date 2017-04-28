// solution to problem 331 of verifying if the preorder serialization of a binary tree is valid. 

#include <stack> 
#include <string> 
#include <iostream> 

using namespace std; 

struct Node { 
    int val; 
    bool leftVisited; // we need to remember if left child has been visited already. 
    
    Node(int num): val(num) {leftVisited = false;}
}; 

void markChild(stack<Node> &s)
{ 
   /* if left child is already visited, then right child is being visited 
    * which means parent should be popped off from the stack */ 
   if (s.top().leftVisited == true) { 
       s.pop();
   } 
   else { 
       s.top().leftVisited = true; 
   }
}

int parseItem(string &s, int &loc)
{ 
    int start = loc; 
    int res = -1;  // assume # as -1. 
    
    while (s[loc] != ',' && loc < s.length()) { 
            ++loc; 
    } 
    
    string num = s.substr(start, loc-start);
        
    if (num != "#") { 
    	res = strtoul(num.c_str(), nullptr, 0);
    }
    
    ++loc; 
    return res;
}


    bool isValidSerialization(string preorder) 
    {
        stack<Node> s; 
        int i=0; 
        int num = parseItem(preorder, i); 
 
        // parse the first item and push on stack. don't push null.    
        if (num != -1) { 
            s.push(num);
        }

        while(i<preorder.length()) {
        
            num = parseItem(preorder, i); 

            if (s.empty()) {
                  return false;
            }

            markChild(s);
        
            if (num != -1) {
                s.push(Node(num));
            }
        }

        return s.empty();
    }

int main() 
{
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << isValidSerialization(s) << endl;  

    string s1 = "9,#,#,1"; 
    cout << isValidSerialization(s1) << endl; 
    cout << isValidSerialization("#") << endl; 
    cout << isValidSerialization("1,#,#") << endl; 
    cout << isValidSerialization("1,#,#,#,#") << endl; 
    cout << isValidSerialization("9,3,0,6,#,#,5,#,4,#,2,#,#,6,0,#,#,#,#") << endl; 
    return 0; 
} 
