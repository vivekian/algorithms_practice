#include <iostream> 
#include <queue> 
#include <string>  

using namespace std; 

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string res = ""; 
	   queue<TreeNode*> q; 

	   if (!root) { 
			return res; 
	   } 
		
		q.push(root); 
		
		while(!q.empty()) { 
			TreeNode* item = q.front(); 
			q.pop(); 
			res += (item) ? to_string(item->val) : "N"; 
	
            // if non-null node, then push the children to be encoded.        
			if (item) { 
				q.push(item->left); 
				q.push(item->right); 	
			} 
			
            // if no items on queue, then tree has been traversed completely. 
			if (!q.empty()) { 
				res += ":";     
			}
 		}

		return res; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) { 
			return nullptr; 
		} 
		
		queue<TreeNode*> q; 	
		auto pos = data.find(":"); 
		string val = (pos != string::npos) ? data.substr(0, pos): data; 
	
		TreeNode* root = new TreeNode(strtol(val.c_str(), nullptr, 10)); 
		q.push(root); 

		// the second check makes sure of the case where there is only root node. 
        while (!q.empty() && pos != string::npos && pos < data.length()) { 
			TreeNode* item = q.front(); 
			q.pop(); 
		
            // its possible that the string is completely parsed.     
            // oldpos is 1 index greater than pos because : is to be skipped.
			auto oldpos = pos+1;  
			pos = data.find(":", oldpos); 
			val = (pos != string::npos) ? data.substr(oldpos, pos - oldpos): 
                                          data.substr(oldpos, data.length()); 
			
			item->left = (val == "N") ? nullptr: 
                                        new TreeNode(strtol(val.c_str(), nullptr, 10)); 
            
            if (item->left) { 
                q.push(item->left); 
            } 

            // repeat this for the right child. 
		    oldpos = pos+1;  
			pos = data.find(":", oldpos); 
			val = (pos != string::npos) ? data.substr(oldpos, pos - oldpos): 
                                          data.substr(oldpos, data.length()); 
                        
			item->right = (val == "N") ? nullptr: 
                                        new TreeNode(strtol(val.c_str(), nullptr, 10)); 
    
            if (item->right) { 
                q.push(item->right); 
            } 
		}

        return root; 
    }
};

int main() 
{ 
	Codec codec; 

	TreeNode root(3); 
	root.left = new TreeNode(4); 
	root.right = new TreeNode(5);
    root.right->right = new TreeNode(6); 
    root.right->left = new TreeNode(7); 
    root.right->left->right = new TreeNode(23); 


	string res = codec.serialize(&root);
    cout << res << endl;  
    auto node = codec.deserialize(res); 
    cout << codec.serialize(node) << endl; 
	cout << codec.serialize(nullptr) << endl;

    TreeNode root1(2); 
    codec.deserialize(codec.serialize(&root1)); 
    return 0;
} 

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
