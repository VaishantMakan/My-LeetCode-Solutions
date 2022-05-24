struct Node {
    Node* links[26];
    
    bool flag = false;
    
    bool containsChar(char c)
    {
        return (links[c - 'a'] != NULL);
    }
    
    void put(char c, Node* newNode)
    {
        links[c - 'a'] = newNode;
    }
    
    Node* get(char c)
    {
        return links[c - 'a'];
    }
    
    void setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        return flag;
    }
    
};

class Trie {
    
private: 
    Node* root;
    
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        Node* temp = root;
        
        for(auto c : word)
        {
            if(!temp->containsChar(c))
            {
                Node* newNode = new Node();
                temp->put(c, newNode);
            }
          
            temp = temp->get(c);
            
        }
        
        temp->setEnd();
    }
    
    bool search(string word) {
        
        Node* temp = root;
        
        for(auto c : word)
        {
            if(!temp->containsChar(c))
            {
                return false;
            }
            else
            {
                temp = temp->get(c);    
            }
        }
        
        return temp->isEnd();
        
    }
    
    bool startsWith(string prefix) {
        
        Node* temp = root;
        
        for(auto c : prefix)
        {
            if(!temp->containsChar(c))
            {
                return false;
            }
            else
            {
                temp = temp->get(c);    
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */