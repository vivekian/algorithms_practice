/* Design an in-memory file system to simulate the following functions:

ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.

mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.

readContentFromFile: Given a file path, return its content in string format.*/ 

#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map> 

using namespace std; 

namespace { 
    struct node { 
        bool isfile; 
        string content; 
        unordered_map<string, node*> children; 

        node(bool file, string data=""): 
            isfile(file), content(data) {}
    }; 
} 

class FileSystem {
public:
    FileSystem() {
       
    }
    
    vector<string> ls(string path) {
        vector<string> res; 

        node* n = getNodeByPath(path); 
        
        if (n) { 
            if (n->isfile) { 
                int j=path.length()-1; 

                while (j>0 && path[j] != '/') { 
                    --j; 
                } 

                res.emplace_back(path.substr(j+1, path.length()-j+1)); 
            } 
            else {   
                for (auto& i: n->children) { 
                   res.emplace_back(i.first); 
                } 
            }
        } 

        sort(res.begin(), res.end()); 
        return res;  
    }
    
    void mkdir(string path) {
        node* curr = &root;  

        for (int i=1; i<path.length(); ++i) { 
            int j=i; 
            
            while (path[i] != '/' && i < path.length()) { 
                ++i; 
            } 

            string dirname = path.substr(j, i-j); 
            if (curr->children.find(dirname) == curr->children.end()) { 
                curr->children.insert({dirname, new node{false}}); 
            }
            
            curr = curr->children[dirname]; 
        } 
    }
    
    void addContentToFile(string filePath, string content) {
        int j = filePath.length()-1; 
        
        while (j > 0 && filePath[j] != '/') { 
            --j; 
        } 
    
        node* n = getNodeByPath(filePath.substr(0, j));

        if (n) {
            string filename = filePath.substr(j+1, filePath.length() - j+1); 
         
            if (n->children.find(filename) == n->children.end()) { 
                n->children.insert({filename, new node(true, content)}); 
            } 
            else { 
                if (n->children[filename]->isfile)
                    n->children[filename]->content += content; 
            } 
        }        
    }
    
    string readContentFromFile(string filePath) {
       string res = ""; 
       node* n = getNodeByPath(filePath);  
        
       if (n) {
          if (n->content.length()) { 
             res = n->content; 
          }
       }

       return res; 
    }

private: 
    node* getNodeByPath(string path) {
        node* curr = &root; 

        for (int i=1; i < path.length(); ++i) { 
            int j=i; 
            
            while (path[i] != '/' && i < path.length()) { 
                ++i; 
            } 

            string dirname = path.substr(j, i-j); 
            if (curr->children.find(dirname) == curr->children.end()) { 
                return nullptr; 
            }
            
            curr = curr->children[dirname]; 
        } 

        return curr;     
    }

    node root = {false, ""}; 
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */

void print(ostream& os, vector<string> &l) { 
    for (auto &i: l) { 
        os << i << " "; 
    }

    os << endl; 
} 

int main() 
{ 
    FileSystem fs; 
    fs.mkdir ("/foo"); 
    fs.mkdir ("/foo/bar"); 
    fs.mkdir ("/foo/bar/a/b/c/d"); 
    fs.mkdir ("/foo/bar/a/b/c/e"); 
    fs.mkdir ("/foo/bar/a/b/c/f"); 
    
    auto res = fs.ls("/foo/bar/a/b/c"); 
    print(cout, res); 

    fs.addContentToFile("/foo/bar/zee", "hello world"); 
    fs.addContentToFile("/foo/bar/a/b/c/hw", "hello world"); 
    fs.addContentToFile("/hw", "hello world"); 
    cout << fs.readContentFromFile("/foo/bar/zee") << endl;      
    cout << fs.readContentFromFile("/foo/bar/a/b/c/hw") << endl;      
    cout << fs.readContentFromFile("/hw") << endl;      
    fs.addContentToFile("/hw", "! Its sunday");
    cout << fs.readContentFromFile("/hw") << endl;   

    fs.addContentToFile("/foo/bar", "hello"); 
    cout << fs.readContentFromFile("/foo/bar") << endl; 
    res = fs.ls("/"); 
    print(cout, res); 
    res = fs.ls("/foo/bar/zee"); 
    print(cout, res); 
    return 0; 
} 
