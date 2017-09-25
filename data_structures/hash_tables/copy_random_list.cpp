#include <unordered_map> 
#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

/**
 * Definition for singly-linked list with a random pointer.*/ 

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
	
	if (!head) 	
		return nullptr; 

	RandomListNode* c1 = head; 
	RandomListNode empty(0); 
	RandomListNode* c2 = &empty; 
	unordered_map<RandomListNode*, RandomListNode*> links; 

	while (c1) { 
		c2->next = new RandomListNode(c1->label); 
		c2 = c2->next; 
		links[c1] = c2; 
		c1 = c1->next; 
	}

	c1 = head; 
	c2 = empty.next; 

	while (c1 && c2) { 
		if (c1->random) { 
			c2->random = links[c1->random]; 
		}
		c1 = c1->next; 
		c2 = c2->next; 
	}

	return empty.next; 
}

int main()
{
    return 0;  
}
