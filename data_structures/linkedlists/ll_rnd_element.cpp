// this is a solution to the problem 382 of leetcode OJ which 
// needs a random item to be returned from a linked list. 

#include <ctime> 
#include <cstdlib> 

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        m_head = head; 
        
        while (head) { 
            ++m_cnt; 
            head=head->next; 
        }
        
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int idx = rand()%m_cnt; 
        int cnt = 0; 
        ListNode* curr = m_head; 
        
        while (cnt < idx) { 
            curr = curr->next; 
            ++cnt; 
        } 
        
        return curr->val; 
    }
    
private: 
    int m_cnt = 0;
    ListNode* m_head; 
};

int main() 
{ 
	return 0; 
} 
