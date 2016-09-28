/* Given  an  arbitrary  ransom  note  string  and  another  string  containing  letters from  all  the  magazines,  write  a  function  that  will  return  true  if  the  ransom   note  can  be  constructed  from  the  magazines ;  otherwise,  it  will  return  false.   

Each  letter  in  the  magazine  string  can  only  be  used  once  in  your  ransom  note.

Note:
You may assume that both strings contain only lowercase letters. */ 

#include <iostream> 
#include <vector> 
#include <string> 

using std::string; 
using std::vector; 
using std::cout; 
using std::endl; 

bool canConstruct(string ransomNote, string magazine) {

	if (ransomNote.empty()) { 
		return true; 
	} 
  
    if (magazine.empty()) { 
		return false; 
	} 

	vector<int> magazine_cnt(26); 
	vector<int> ransom_cnt(26);

    for (int i=0; i<26; ++i) { 
        magazine_cnt[i] = 0; 
        ransom_cnt[i] = 0; 
    } 

	for (const char& c: magazine) { 
		magazine_cnt[c-'a']++; 
	} 

	for (const char& c: ransomNote) { 
		ransom_cnt[c-'a']++; 
	} 

	for (int i=0; i<26; ++i) { 
		if (ransom_cnt[i] > magazine_cnt[i]) { 
			return false; 
		} 
	}

	return true; 
}

int main() 
{ 
	cout << canConstruct(string("a"), string("abc")) << endl; 
	cout << canConstruct(string("abc"), string("abx")) << endl; 
	cout << canConstruct(string(""), string("abx")) << endl; 
	return 0; 
} 
