#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

struct NodeInfo { 
	ListNode *node; 
	int index; 
	
	NodeInfo(ListNode* n, int i): node(n), index(i) {}  
}; 

ListNode* mergeKLists(vector<ListNode*>& lists) {

	ListNode head(0); 
	ListNode* curr = &head; 

	auto cmp = [](const NodeInfo& a, const NodeInfo& b) 
				 { return a.node->val > b.node->val; };
	priority_queue<NodeInfo, vector<NodeInfo>, decltype(cmp)> pq(cmp); 

    // add the first node of each list to the heap to form a heap of size k. 
	for (int i=0; i<lists.size(); ++i) { 
		if (lists[i]) { 
			pq.push({lists[i], i}); 
			lists[i] = lists[i]->next; 
		}
	} 

    // pop item of the priority queue, add it to the merged queue, iterate 
    // the list, remove item from list and push it to the priority queue. 
	while (!pq.empty()) { 
		auto item = pq.top(); 
		pq.pop(); 
		
		curr->next = item.node; 
		curr = curr->next; 
		
		if (lists[item.index]) {
			pq.push({lists[item.index], item.index}); 
			lists[item.index] = lists[item.index]->next; 
		} 
	} 
	
	return head.next;         
}

int main()
{
	return 0;  
}
